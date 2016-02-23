#ifndef __libcpptest__
#define __libcpptest__

#include <string>
#include <chrono>
#include <functional>

namespace cpptest
{

class Module
{
    std::chrono::high_resolution_clock::time_point start_time;
    bool report_time = false;
    const std::string module_name;
    unsigned int passed = 0;
    unsigned int failed = 0;

public:
    Module(std::string module_name);
    ~Module();
    void set_report_time(bool flag);
    void report(std::string case_name, bool test_success);
    void fn(std::string case_name, std::function<bool()> f);
};

} // namespace cpptest

#endif 
