#pragma once

#include "../visitor.hpp"

namespace renn::ast {

class BaseNode {
  public:
    virtual ~BaseNode() = default;

    virtual void accept(AstVisitor& visitor) = 0;
};

}  // namespace renn::ast
