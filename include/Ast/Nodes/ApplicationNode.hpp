#pragma once

#include "../visitor.hpp"
#include "BaseNode.hpp"

namespace renn::ast::nodes {

template <typename U, typename InputExpr, typename Func>
class ApplicationNode : public BaseNode {
  private:
    InputExpr input_;
    Func functor_;

  public:
    void accept(AstVisitor& visitor) override;
};

}  // namespace renn::ast::nodes
