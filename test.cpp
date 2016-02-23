#include <cpptest.hpp>

bool passing_test()
{
    return true;
}

bool failing_test()
{
    return false;
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
}

