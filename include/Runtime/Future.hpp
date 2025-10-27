#pragma once

#include "../Core/Common.hpp"
#include <atomic>
#include <memory>

using namespace renn;

namespace renn::execution {

template <typename T>
class Future {
  private:
    struct SharedState {
        renn::core::common::Result<T> res_;
        std::atomic<bool> ready_;
        /* IExecutor* executor_; */
    };

    std::shared_ptr<SharedState> state_;

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
};

};  // namespace renn::execution
