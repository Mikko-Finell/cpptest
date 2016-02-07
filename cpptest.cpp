#include <iomanip>
#include <iostream>
#include <cpptest.hpp>

cpptest::Module::Module(std::string module_name) {
    std::cout<<'\n'<<"Running tests for "<<'"'<<module_name<<'"'<<"..."<<'\n';
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
    std::cout<<"Passed: "<<passed<<"/"<<num_tests;
    std::cout<<std::fixed<<std::setprecision(1)<<" ("<<rate<<"%)\n\n";
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
