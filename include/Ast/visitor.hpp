#pragma once

namespace renn::ast {

class AstVisitor {
  private:
  public:
    virtual ~AstVisitor() = default;

    virtual void visit() = 0;
};
}  // namespace renn::ast
