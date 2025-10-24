#pragma once

#include <exception>
#include <expected>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

namespace renn::core::common {

struct Error;

template <typename F, typename... Args>
using R = std::invoke_result_t<F, Args...>;

template <typename Ok>
using Result = std::expected<Ok, Error>;

template <typename E>
using Err = std::unexpected<E>;

struct Error {
    std::string message_;
    std::string category_;
    std::exception_ptr exception_;
    std::vector<std::string> context_;

    template <typename E>
    static Error from(E&& err) {
        if (std::is_base_of_v<std::exception, E>) {
            return Error(
                err.what(),
                typeid(E).name(),
                std::make_exception_ptr(err));
        } else {
            /* for any other types we convert errors to string description */
            std::ostringstream oss;
            oss << err;

            return Error(
                oss.str(),
                typeid(E).name(),
                {});
        }
    }

    void rethrow() const {
        if (exception_) {
            std::rethrow_exception(exception_);
        }
        /* there is no exception ptr, hence we throw runtime error with description */
        throw std::runtime_error(message_);
    }
};


};  // namespace renn::core::common
