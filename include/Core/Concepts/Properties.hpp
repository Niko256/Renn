#pragma once

#include <concepts>
#include <optional>
#include <type_traits>

namespace renn::core::concepts::properties {

/*
 * this concept represents pure value type
 * ???
 */
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

/*
 * How to describe these restrictions in formal way?
 */
template <typename Func, typename InputType, typename TransformedType>
concept Transformer = Invokable<Func, InputType, TransformedType> &&
                      std::convertible_to<std::invoke_result_t<Func, InputType>, TransformedType>;

template <typename Func, typename InputType, typename TransformedType>
concept OptionalTransformer = Transformer<Func, InputType, std::optional<TransformedType>>;


template <typename Func, typename... Args>
concept NoThrowInvokable = Invokable<Func, Args...> && std::is_nothrow_invocable_v<Func, Args...>;


template <typename T, typename... Funcs>
concept ParallelTransforms = (std::invocable<Funcs, T> && ...);


}  // namespace renn::core::concepts::properties
