#pragma once

#include <concepts>
#include <iterator>
#include <type_traits>

namespace renn::core::concepts::containers {

template <typename Cont, typename T>
concept Container = requires(Cont container) {
    typename Cont::value_type;

    { container.begin() } -> std::input_iterator;
    { container.end() } -> std::input_iterator;
    { container.size() } -> std::convertible_to<std::size_t>;
};

}  // namespace renn::core::concepts::containers
