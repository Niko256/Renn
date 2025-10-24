#pragma once

#include "../Common.hpp"
#include <memory>
#include <vector>

namespace renn::core::nodes {

template <typename T>
class BaseNode {
  private:
    std::vector<std::unique_ptr<BaseNode<T>>> dependencies_;
    std::string node_id_;

  public:
    virtual renn::core::common::Result<T> execute() const = 0;


    virtual ~BaseNode() = default;
    virtual std::vector<std::unique_ptr<BaseNode>> get_dependencies() const = 0;
    virtual std::string get_name() const = 0;
};

};  // namespace renn::core::nodes
