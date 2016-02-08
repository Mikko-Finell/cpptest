#ifndef __libcpptest__
#define __libcpptest__

#include <string>
#include <chrono>

namespace cpptest {

class Module {
    std::chrono::high_resolution_clock::time_point start_time;
    bool report_time = false;
    const std::string module_name;
    unsigned int passed = 0;
    unsigned int failed = 0;

public:
    Module(std::string module_name);
    void set_report_time(bool flag);
    void test(std::string case_name, bool test_success);
    ~Module();
};

}

#endif 
