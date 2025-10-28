#pragma once

#include <atomic>

class Event {
    /*!
     *  private:
     *    std::atomic<std::uint_32t> ready_{0};
     *  public:
     *
     *    void wait() {
     *       futex::wait(ready_, 0);
     *    }
     *
     *    void fire() {
     *      auto wake_key = futex::prepare_wake(ready_);
     *      ready_.store(1);
     *      futex::wake_all(wake_key);
     *    }
     */
};
