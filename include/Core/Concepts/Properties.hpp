#pragma once

#include <type_traits>

namespace comp::concepts::properties {

template <typename T>
concept Pure =
    std::is_nothrow_copy_constructible_v<T> &&
    std::is_nothrow_destructible_v<T> &&

    requires {
        requires !std::is_pointer_v<T>;
        requires !std::is_reference_v<T>;
    };


template <typename T>
concept Movable =
    std::is_nothrow_move_constructible_v<T> &&
    std::is_nothrow_move_assignable_v<T>;


template <typename T>
concept Copyable =
    Movable<T> &&
    std::is_nothrow_copy_constructible_v<T> &&
    std::is_nothrow_copy_assignable_v<T>;


template <typename Func, typename... Args>
concept Invokable = std::is_invocable_v<Func, Args...>;


template <typename Func, typename... Args>
concept NoThrowInvokable = Invokable<Func, Args...> && std::is_nothrow_invocable_v<Func, Args...>;

template <typename Func, typename Res, typename... Args>
concept InvokableTo =
    Invokable<Func, Args...> && std::is_same_v<std::invoke_result_t<Func, Args...>, Res>;

}  // namespace comp::concepts::properties
