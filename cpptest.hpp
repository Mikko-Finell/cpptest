#ifndef CPPTEST
#define CPPTEST

#include <iostream>
#include <string>
#include <future>
#include <functional>
#include <list>

namespace Test {

class Module {
    std::list<std::future<bool>> results;
    std::list<std::string> cases;
    const std::string module_name;
    void report() {
        if (module_name != "")
            std::cout << '\n' << "Report for module \""
                      << module_name << "\":\n";

        std::list<std::string> failed;
        for (auto& result : results) {
            if (result.get() == false)
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
public:
    std::launch policy = std::launch::async;
    Module(const std::string & name = "") : module_name(name) {}
    ~Module() { report(); }
    void fn(const std::string & s, const std::function<bool()> & f) {
        cases.push_back(s);
        results.push_back(std::async(policy, f));
    }
};

} // namespace Test

#endif // CPPTEST
