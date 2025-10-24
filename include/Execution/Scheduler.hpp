#pragma once

#include <atomic>
#include <unordered_map>

namespace renn::execution {

class Task {
  public:
    virtual ~Task() = default;

    std::atomic<bool> is_ready_;

    bool is_ready() const;
};

class TaskScheduler {
  private:
    /* *std::unordered_map<NodeId, Task> task_pool_; */
    /* ThreadPool */
};


};  // namespace renn::execution
