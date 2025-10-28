#pragma once

#include "Common.hpp"
#include "SharedState.hpp"
#include "StateMachine.hpp"
#include <optional>

namespace renn::core {

template <typename T>
class SharedState {
  private:
    StateMachine rendezvouz_;
    std::optional<common::Result<T>> result_;
    std::optional<common::Callback<T>> callback_;

  public:
    void produce(common::Result<T> r);

    void consume(common::Callback<T> callback);

    void rendezvouz() {
        (*callback_)(std::move(*result_));
        delete this;
    }
};


};  // namespace renn::core
