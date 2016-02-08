#include "cpptest.hpp"

bool passing_test() {
    return true;
}

bool failing_test() {
    return false;
}

int main() {
    cpptest::Module meta{"test the test"};
    meta.set_report_time(true);
    meta.test("passing test", passing_test());
    meta.test("failing test", failing_test());
    meta.test("another passing test", passing_test());
    meta.test_fn("failing lambda", []{ return false; });
    meta.test_fn("passing lambda", []{ return true; });
}

