#pragma once

#include "Properties.hpp"
#include <concepts>
#include <future>

namespace renn::core::concepts::expressions {

template <typename E>
concept Expr = requires(const E& expr) {
    typename E::result_type_;

    requires properties::Copyable<E>;
};

template <typename E>
concept EvaluableExpr = Expr<E> && requires(const E& expr) {
    { expr.eval() } -> std::same_as<typename E::result_type_>;
    { expr.async_eval() } -> std::convertible_to<std::future<typename E::result_type_>>;
};


template <typename E>
concept ValueExpr = Expr<E> && requires(const E& expr) {
    requires std::constructible_from<E, typename E::result_type_>;
    { expr.value() } -> std::same_as<const typename E::result_type_&>;
};


template <typename E, typename InputExpr>
concept UnaryOpExpr =
    Expr<E> && Expr<InputExpr> &&
    requires(const E& expr) {
        typename E::input_type_;
        requires std::same_as<typename E::input_type_, InputExpr>;
    };


template <typename E, typename LeftInExpr, typename RightInExpr>
concept BinaryOpExpr =
    Expr<E> && Expr<LeftInExpr> && Expr<RightInExpr> &&
    requires(const E& expr) {
        typename E::left_type_;
        typename E::right_type_;

        requires std::same_as<typename E::left_type_, LeftInExpr>;
        requires std::same_as<typename E::right_type_, RightInExpr>;
    };


template <typename E, typename... InputExprs>
concept NaryOpExpr =
    Expr<E> && (Expr<InputExprs> && ...) &&
    requires(const E& expr) {
        /* => This expression stores tuple of input expressions */
        typename E::input_types_;
    };

}  // namespace renn::core::concepts::expressions
