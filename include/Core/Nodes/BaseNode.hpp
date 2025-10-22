#pragma once

#include <memory>
#include <vector>

class BaseNode {
  private:
    std::vector<std::unique_ptr<BaseNode>> dependencies_;

  public:
    virtual ~BaseNode() = default;
    virtual std::vector<std::unique_ptr<BaseNode>> get_dependencies() const = 0;
    virtual std::string get_name() const = 0;
};
