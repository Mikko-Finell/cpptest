#ifndef __libcpptest__
#define __libcpptest__

#include <string>

namespace cpptest {

class Module {
    const std::string module_name;
    unsigned int passed = 0;
    unsigned int failed = 0;

public:
    Module(std::string module_name);
    void test(std::string case_name, bool test_success);
    ~Module();
};

}

#endif 
