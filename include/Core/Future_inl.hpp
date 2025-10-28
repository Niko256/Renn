#include "Event.hpp"

template <typename T>
T renn::core::Future<T>::get() {
    check_state();

    std::optional<common::Result<T>> result;
    Event ready;
    release_state()->consume([&](common::Result<T> r) {
        result.emplace(std::move(r));
        ready.fire();
    });

    ready.wait();
    return unwrap(std::move(*result));
}
