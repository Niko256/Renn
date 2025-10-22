#pragma once

#include "Properties.hpp"
#include <concepts>

namespace renn::core::concepts::expressions {

template <typename E>
concept Expr = requires(const E& expr) {
    typename E::result_type_;

    requires properties::Copyable<E>;
};


template <typename E>
concept ValueExpr = Expr<E> && requires(const E& expr) {
    requires std::constructible_from<E, typename E::result_type_>;
    { expr.value() } -> std::same_as<const typename E::result_type_&>;
};


template <typename T, typename F>
concept Reducer = requires(T lhs, T rhs, F reducer) {
    { reducer(lhs, rhs) } -> std::convertible_to<T>;
};

}  // namespace renn::core::concepts::expressions
