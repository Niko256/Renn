#pragma once

namespace renn::core {

template <typename T>
class Expression {

  public:
    /*
     * [ API ] :
     */

    /* Value : T -> Expression<T> */
    static Expression<T> value(T&& value);

    /* Then: Expression<T> -> (T -> U) -> Expression<U> */

    /* Every : Expression<T> -> (T -> U1) × ... × (T -> Un) -> Expression<tuple<U1, ... , Un>> */

    /* Map : Expression<vector<T>> -> (T -> U) -> Expression<vector<U>> */

    /* FlatMap : Expression<vector<T>> -> (T -> vector<U>) -> Expression<vector<U>> */

    /* Fold : Expression<vector<T>> ->(T × T ->T) ->T ->Expression<T> */

    /* If : Expression<T> -> (T -> bool) -> (T -> U) -> (T -> U) -> Expression<U> */

    /* Zip : Expression<vector<T_1>> × Expression<vector<T_2>> -> (T_1 × T_2 -> U) -> Expression<vector<U>> */

    /* Unzip : Expression<vector<tuple<T_1, T_2>>> -> Expression<tuple<vector<T_1>, vector<T_2>>> */

    /* Rec<T> : () -> RecExpression<T>
     * Recurse : RecExpression<T> -> ((T -> U) × T -> U) -> Expression<U>
     */

    /* All : Expression<T> -> vector<(T -> U)> -> Expression<vector<U>> */

    /* Any : Expression<T> -> vector<(T -> optional<U>)> -> Expression<U> */

    /* Project : Expression<tuple<T_1,...,T_n>> -> (optional<(T_1 -> U_1)>, ..., optional<(T_n -> U_n)>) -> Expression<tuple<U_j,...>> */

    /* JoinValues : Expression<tuple<T_1,...,T_n>> -> (U_1, ..., U_m) -> Expression<tuple<T_1,...,T_n, U_1,...,U_m>> */

    /* Switch : Expression<T> -> (T -> K) -> SwitchBuilder<K, T> */

    /* Case : SwitchBuilder<K, T> -> K -> (T -> U) -> SwitchBuilder<K, T> */

    /* Default : SwitchBuilder<K, T> -> (T -> U) -> Expression<U> */
};
}  // namespace renn::core
