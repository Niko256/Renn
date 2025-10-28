#pragma once


#include <atomic>
#include <cstdint>

class StateMachine {
  private:
    struct States {
        enum _ : uint_fast64_t {
            Init = 0,
            Consumer = 1,
            Producer = 2,
            Both = Consumer | Producer
        };
    };

    std::atomic<uint_fast64_t> state_{States::Init};

    bool produce() {
        return state_.fetch_or(States::Producer) == States::Consumer;
    }

    bool consume() {
        return state_.fetch_or(States::Consumer) == States::Producer;
    }
};
