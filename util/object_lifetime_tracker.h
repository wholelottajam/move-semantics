#pragma once

#include <iostream>
#include <string>

#include <fmt/core.h>

struct Marker {
    inline static u_int32_t counter = 0;
    u_int32_t id;
    char const* state;
    ~Marker() {
        state = "destructed";
        fmt::print("id: {} state: {}\n", id, state);
    }
    Marker() : state{"constructed"} {
        counter++;
        id = counter;
        fmt::print("id: {} state: {}\n", id, state);
    }
    Marker(Marker const&) noexcept : state{"copy constructed"} {
            counter++;
            id = counter;
            fmt::print("id: {} state: {}\n", id, state);
    }
    Marker(Marker&& other) noexcept : state{"move constructed"} {
            counter++;
            id = counter;
            other.state = "moved from object";
            fmt::print("id: {} state: {}\n", id, state);
    }
    Marker& operator=(Marker const&) noexcept {
        state = "copy assigned";
        fmt::print("id: {} state: {}\n", id, state);
        return *this;
    }
    Marker& operator=(Marker&& other) noexcept {
        state = "move assigned";
        other.state = "moved from object";
        fmt::print("id: {} state: {}\n", id, state);
        return *this;
    }
};