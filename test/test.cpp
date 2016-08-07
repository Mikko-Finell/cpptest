#include <iostream>
#include <cpptest.hpp>

bool passing_test()
{
    return true;
}

bool failing_test()
{
    return false;
}

bool allok_yes()
{
    std::cout.setstate(std::ios_base::failbit);
    bool result = false;
    {
        cpptest::Module test{""};
        test.fn("", []{ return true; });
        result = test.allok();
    }
    std::cout.clear();
    return result;
}

bool allok_no()
{
    std::cout.setstate(std::ios_base::failbit);
    bool result = false;
    {
        cpptest::Module test{""};
        test.fn("", []{ return false; });
        result = test.allok();
    }
    std::cout.clear();
    return !result;
}

int main()
{
    cpptest::Module meta{"test the test"};
    meta.set_report_time(true);
    meta.report("passing test", passing_test());
    meta.report("failing test", failing_test());
    meta.report("another passing test", passing_test());
    meta.fn("function pointer", passing_test);
    meta.fn("failing lambda", []{ return false; });
    meta.fn("passing lambda", []{ return true; });
    meta.fn("allok yes", allok_yes);
    meta.fn("allok no", allok_no);
}

