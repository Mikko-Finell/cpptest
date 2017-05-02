#ifndef CPPTEST
#define CPPTEST

#include <iostream>
#include <string>
#include <functional>
#include <list>

namespace cpptest {

class Module {
    std::list<std::function<bool()>> results;
    std::list<std::string> cases;
    const std::string module_name;

public:
    Module(const std::string & name = "") : module_name(name) {}
    ~Module() {
        if (module_name != "")
            std::cout << '\n' << "Report for module \""
                      << module_name << "\":\n";

        std::list<std::string> failed;
        for (auto& test : results) {
            if (test() == false)
                failed.push_back(cases.front());
            cases.pop_front();
        }
        std::cout << '\n'
                  << results.size() - failed.size()
                  << "/" << results.size() << " tests passed.\n";
        if (!failed.empty())
            std::cout << "\nFailed tests:\n";
        for (auto& test : failed)
            std::cout << " * " << test << '\n';

        std::cout << std::endl;
    }
    void fn(const std::string & s, const std::function<bool()> & fn) {
        cases.push_back(s);
        results.push_back(fn);
    }
};

} // namespace Test

#endif // CPPTEST
