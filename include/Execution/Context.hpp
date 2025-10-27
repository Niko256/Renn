#pragma once

#include "Executor.hpp"
#include <memory>

namespace renn::execution {


class ExecutionContext {
  private:
    IExecutor* executor_;
    std::shared_ptr<TaskGraph> graph_;
    ErrorHandler handler_;

    struct SharedState {};
};


};  // namespace renn::execution
