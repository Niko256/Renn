#pragma once

#include <concepts>

/* we want to be sure that object Func could be invoked with pack of arguments Args... */
template <typename Func, typename... Args>
concept Callable = requires(Func&& f, Args&&... args) {
    { f(args...) };
};
