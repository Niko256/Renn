#pragma once

#include "../../Core/Concepts/Properties.hpp"
#include "../Nodes/BaseNode.hpp"
#include "../visitor.hpp"

namespace renn::ast {

using namespace renn::core::concepts;

template <expressions::Expr InputExpr, >
class ThenNode : public BaseNode {
  private:
    /* => Each new node stores shared_ptr of the previous one */
    PrevNode input_;
    Func functor_;

    using result_type_ = U;

  public:
    void accept(AstVisitor& visitor) override;
};

}  // namespace renn::ast
