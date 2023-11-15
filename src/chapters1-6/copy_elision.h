#pragma once

namespace copy_elision {
    // -fno-elide-constructors compiler flag can be used to disable copy elision
    void test_bad_std_move();
    void test_bad_2();
    void test_good();
    void test_good_2();
}