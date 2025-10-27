#pragma once

#include "../Core/Common.hpp"
#include "Future.hpp"
#include <functional>

namespace renn::execution {

class IExecutor {
    virtual ~IExecutor() = default;
    /* let me think about the signature and especially for parameter */

    template <typename F>
    auto submit(F&& func) -> Future<core::common::R<F>>;
};
}  // namespace renn::execution
