#pragma once

#include "Future.hpp"
#include "SharedState.hpp"
#include <exception>

namespace renn::core {

template <typename T>
class Promise {
  private:
    core::SharedState<T>* state_;
    core::Future<T> future_;

  public:
    /* Non-copyable (one-shot channel) */
    Promise(const Promise& other) = delete;
    Promise& operator=(const Promise& other) = delete;

    /* Movable */
    Promise(Promise&& pr) : state_(std::move(pr.release_state())),
                            future_(std::move(pr.future_)) {}

    /* Non-move-assignable */
    Promise& operator=(Promise&& other) = delete;

    void set_value(T value);

    void set_exception(std::exception_ptr eptr);

    Future<T> make_future() {
        return std::move(future_);
    }

    static SharedState<T> no_state() {
        return nullptr;
    }

    SharedState<T> release_state() {
        return std::move(state_);
    }
};


};  // namespace renn::core
