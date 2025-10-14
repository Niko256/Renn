#pragma once

#include "../../Core/Concepts/Expressions.hpp"
#include "../Nodes/BaseNode.hpp"
#include "../visitor.hpp"

namespace renn::ast {

using namespace renn::core::concepts;

template <typename U, expressions::Expr PrevNode, properties::Invokable<U> Func>
class ApplicationNode : public BaseNode {
  private:
    PrevNode input_;
    Func functor_;

  public:
    void accept(AstVisitor& visitor) override;
};

}  // namespace renn::ast
