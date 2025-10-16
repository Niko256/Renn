#pragma once

namespace renn::ast {

class AstVisitor {
  public:
    virtual ~AstVisitor() = default;

    virtual void visit() = 0;
};
}  // namespace renn::ast
