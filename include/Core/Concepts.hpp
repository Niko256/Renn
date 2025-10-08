#pragma once

#include <concepts>

// we want to be sure that object Func could be invoked with pack of arguments Args...
template <typename Func, typename... Args>
concept InvokableWith = requires(Func&& f, Args&&... args) {
    { f(args...) };
};
