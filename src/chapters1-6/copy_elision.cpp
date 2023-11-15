#include "copy_elision.h"
#include <object_lifetime_tracker.h>

using namespace util;

namespace copy_elision {

    TestClass bad() {
        TestClass tc;
        return std::move(tc); // bad don't do this
    }

    TestClass good() {
        TestClass tc;
        return tc;
    }

    /// \brief without std::move, compiler can use rvo
    ///        the object is constructed in the caller's scope
    ///        with std::move, rvo is disabled. it will use copy/move semantics
    void test_bad_std_move() {
        auto test = bad();
    }

    /// \brief this one doesn't disable nrvo. it won't use move/copy semantics. The result
    ///         will be directly constructed at caller.
    void test_good() {
        auto test = good();
    }

    /// \brief without std::move, compiler can use rvo
    ///        the object is constructed in the caller's scope
    ///        with std::move, rvo is disabled. it will use copy/move semantics two times
    void test_bad_2() {
        auto test {std::move(bad())};
    }
    /// \brief this one doesn't disable nrvo. it will create the first one and then move single time
    void test_good_2() {
        auto test {bad()};
    }
}