#include <iomanip>
#include <iostream>
#include <cpptest.hpp>

cpptest::Module::Module(std::string module_name)
    : start_time(std::chrono::high_resolution_clock::now())
{
    std::cout<<'\n'<<"Running tests for "<<'"'<<module_name<<'"'<<"..."<<'\n';
}

void cpptest::Module::set_report_time(bool flag) {
    report_time = flag;
}

cpptest::Module::~Module() {
    auto num_tests = passed + failed;
    double rate = 0.0;
    if (num_tests == 0) {
        std::cout<<"No tests yet..."<<std::endl;
        return;
    } else if (passed != 0) {
        rate = 100 * (double(passed) / double(num_tests));
    }
    std::cout<<"Passed: "<<passed<<"/"<<num_tests
             <<std::fixed<<std::setprecision(1)<<" ("<<rate<<"%)\n";
    if (report_time) {
        auto dt = std::chrono::high_resolution_clock::now() - start_time;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt);
        std::cout<<"Completed in "<<ms.count()<<"ms\n"<<std::endl;
    } else {
        std::cout<<std::endl;
    }

}

void cpptest::Module::test(std::string case_name, bool test_success) {
    auto NORMAL = "\x1B[0m";
    auto RED    = "\x1B[31m";
    auto GREEN  = "\x1B[32m";
    if (test_success) {
        passed++;
        std::cout<<" ["<<GREEN<<"PASSED"<<NORMAL<<"] ";
    } else {
        failed++;
        std::cout<<" ["<<RED<<"FAILED"<<NORMAL<<"] ";
    }
    std::cout<<case_name<<std::endl;
}
