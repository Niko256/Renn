#pragma once

#include "../../Core/Concepts/Properties.hpp"
#include "../Nodes/BaseNode.hpp"
#include "../visitor.hpp"
#include <memory>

namespace renn::ast {

using namespace renn::core::concepts;

template <typename U, typename PrevNode, properties::Invokable<U> Func>
class ThenNode : public BaseNode {
  private:
    /* => Each new node stores shared_ptr of the previous one */
    PrevNode input_;
    Func functor_;

  public:
    void accept(AstVisitor& visitor) override;
};

}  // namespace renn::ast
