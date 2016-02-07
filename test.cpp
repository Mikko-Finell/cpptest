#include "libcpptest.hpp"

bool passing_test() {
    return true;
}

bool failing_test() {
    return false;
}

int main() {
    cpptest::Module meta{"test the test"};
    meta.test("passing test", passing_test());
    meta.test("failing test", failing_test());
    meta.test("another passing test", passing_test());
}

