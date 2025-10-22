#pragma once

#include <expected>
#include <type_traits>

namespace renn::core::details {

template <typename F, typename... Args>
using result_type = std::invoke_result_t<F, Args...>;

template <typename Ok, typename Err>
using Result = std::expected<Ok, Err>;


};  // namespace renn::core::details
