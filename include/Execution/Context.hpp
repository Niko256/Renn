#pragma once

#include "Scheduler.hpp"
#include <memory>

namespace renn::execution {


class ExecutionContext {
  private:
    std::shared_ptr<TaskScheduler> scheduler_;
    ErrorHandler handler_;
};


};  // namespace renn::execution
