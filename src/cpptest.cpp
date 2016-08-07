#include <iomanip>
#include <iostream>
#include <cpptest.hpp>

cpptest::Module::Module(std::string module_name)
    : start_time(std::chrono::high_resolution_clock::now())
{
    std::cout<<'\n'<<"Running tests for "<<'"'<<module_name<<'"'<<"..."<<'\n';
}

cpptest::Module::~Module()
{
    const auto num_tests = passed + failed;
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
        using namespace std::chrono;
        const auto dt = high_resolution_clock::now() - start_time;
        const auto ms = duration_cast<milliseconds>(dt);
        std::cout<<"Completed in "<<ms.count()<<"ms\n"<<std::endl;
    } else {
        std::cout<<std::endl;
    }
}

void cpptest::Module::set_report_time(bool flag)
{
    report_time = flag;
}

void cpptest::Module::report(std::string case_name, bool test_success)
{
    const auto NORMAL = "\x1B[0m";
    const auto RED    = "\x1B[31m";
    const auto GREEN  = "\x1B[32m";
    if (test_success) {
        passed++;
        std::cout<<" ["<<GREEN<<"PASS"<<NORMAL<<"] ";
    } else {
        failed++;
        std::cout<<" ["<<RED<<"FAIL"<<NORMAL<<"] ";
    }
    std::cout<<case_name<<std::endl;
}

void cpptest::Module::fn(std::string case_name, std::function<bool()> f)
{
    return report(case_name, f());
}

bool cpptest::Module::allok() const
{
    return passed > 0 && failed == 0;
}
