#pragma once

#include "../visitor.hpp"
#include "BaseNode.hpp"
#include <algorithm>

namespace renn::ast {


template <typename ValueType>
class ValueNode : public BaseNode {
  private:
    ValueType value_;

  public:
    ValueNode(ValueType value) : value_(std::move(value)) {}

    const ValueType get_value() const;

    void set_value(ValueType value);

    /* Method that tell Visitor about *this Node*/
    void accept(AstVisitor& visitor) override;
};
}  // namespace renn::ast
