#pragma once

#include "Common.hpp"
#include "Nodes/BaseNode.hpp"
#include <future>
#include <memory>
#include <tuple>
#include <vector>

namespace renn::core {


template <typename T>
class Expression {
  private:
    std::shared_ptr<nodes::BaseNode<T>> root_;

  public:
    renn::core::common::Result<T> Eval() = 0;

    std::future<common::Result<T>> AsyncEval() = 0;

    /* ------------------------------------------------------------ */


    /*
     * [ COMBINATORS ] :
     */

    /* Value : T -> Expression<T> */
    static Expression<T> value(T&& value);

    /* Then: Expression<T> -> (T -> R) -> Expression<R> */
    template <typename F>
    auto Then(F&& func) const -> Expression<common::R<F>>;

    /* Every : Expression<T> -> (T -> R1) × ... × (T -> Rn) -> Expression<tuple<R1, ... , Rn>> */
    template <typename... Fs>
    auto Every(Fs&&... funcs) const;

    /* Map : Expression<vector<T>> -> (T -> R) -> Expression<vector<R>> */
    template <typename F, typename R = T, typename Container>
    auto Map(F&& transform) const;

    /*
     *
     * FlatMap : Expression<vector<T>> -> (T -> vector<R>) -> Expression<vector<R>>
     * ![TO-DO]! :: Think about :
     *  - signature (maybe it has to be generilized)
     *  - input container (maybe i should make concept for it)
     */
    template <typename F>
    auto FlatMap(F&& trasform) const;

    /* Fold : Expression<vector<T>> ->(T × T ->T) ->T ->Expression<T> */
    template <typename F>
    auto Fold(F&& reducer) const;

    /* If : Expression<T> -> (T -> bool) -> (T -> R) -> (T -> R) -> Expression<R> */
    template <typename Pred, typename ThenF, typename ElseF>
    auto If(Pred&& predicate, ThenF&& then_f, ElseF&& else_f) const;

    /* Zip : Expression<vector<T_1>> × Expression<vector<T_2>> -> (T_1 × T_2 -> R) -> Expression<vector<R>> */
    template <typename... Ts>
    auto Zip() const -> Expression<std::vector<Ts...>>;

    /* R_n zip : Expression<vector<tuple<T_1, T_2>>> -> Expression<tuple<vector<T_1>, vector<T_2>>> */
    template <typename T1, typename T2>
    auto RnZip(Expression<std::vector<T1, T2>>) -> Expression<std::tuple<std::vector<T1>, std::vector<T2>>>;

    /* Rec<T> : () -> RecExpression<T>
     * Recurse : RecExpression<T> -> ((T -> R) × T -> R) -> Expression<R>
     */

    /* All : Expression<T> -> vector<(T -> R)> -> Expression<vector<R>> */
    template <typename F>
    auto All(F&& func) -> Expression<std::vector<common::R<F>>>;

    /* Any : Expression<T> -> vector<(T -> optional<R>)> -> Expression<R> */
    template <typename F>
    auto Any(F&& func) -> Expression<common::R<F>>;

    /* Project : Expression<tuple<T_1,...,T_n>> -> (optional<(T_1 -> R_1)>, ..., optional<(T_n -> R_n)>) -> Expression<tuple<R_j,...>> */
    template <typename... Ts, typename F>
    auto Project(F&& func) -> Expression<std::tuple<common::R<F, Ts>>...>;

    /* JoinValues : Expression<tuple<T_1,...,T_n>> -> (R_1, ..., R_m) -> Expression<tuple<T_1,...,T_n, R_1,...,R_m>>
     * ??? [TO-DO] :: write signature [how to combine Ts... and Rs...]?
     */

    /* Switch : Expression<T> -> (T -> K) -> SwitchBuilder<K, T> */

    /* Case : SwitchBuilder<K, T> -> K -> (T -> R) -> SwitchBuilder<K, T> */

    /* Default : SwitchBuilder<K, T> -> (T -> R) -> Expression<R> */
};
}  // namespace renn::core
