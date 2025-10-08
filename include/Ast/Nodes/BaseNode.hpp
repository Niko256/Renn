#pragma once

#include "../visitor.hpp"

class BaseNode {
  public:
    virtual ~BaseNode() = default;

    virtual void accept(IVisitor& visitor) = 0;
};
