#pragma once

#include "../Core/Common.hpp"
#include <atomic>
#include <memory>

using namespace renn;

namespace renn::core {

template <typename T>
class Future {
  private:
  public:
    template <typename F>
    Future<core::common::R<F, T>> then(F&& callback);

    /*
     * [ TO-DO ] : IMPLEMENT PIPELINE OPERATOR '|'
     * this is more eligible and functional way to express chain of async operations
     */
    template <typename Combinator>
    auto operator|(Future<T> future, Combinator combinator);

    template <typename F>
    auto Spawn() -> Future<core::common::R<F>>;

    bool is_ready() const;

    T get();

    void check_state();

    auto release_state();
};

};  // namespace renn::core

#include "Future_inl.hpp"
