#pragma once

#include "../../Core/Concepts/Properties.hpp"
#include "../visitor.hpp"
#include "BaseNode.hpp"
#include <algorithm>

namespace renn::ast {

using namespace core::concepts;

template <properties::Pure ValueType>
class ValueNode : public BaseNode {
  private:
    using result_type_ = ValueType;

    ValueType value_;

  public:
    ValueNode(ValueType value) : value_(std::move(value)) {}

    const ValueType get_value() const;

    void set_value(ValueType value);

    /* Method that tell Visitor about *this Node*/
    void accept(AstVisitor& visitor) override;
};
}  // namespace renn::ast
