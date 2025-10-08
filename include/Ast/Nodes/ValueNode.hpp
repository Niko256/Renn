#pragma once

#include "../visitor.hpp"
#include "BaseNode.hpp"

template <typename ValueType>
class ValueNode : public BaseNode {
  private:
    ValueType m_value_;

  public:
    ValueNode(ValueType value) : m_value_(value) {}

    const ValueType get_value() const;

    void set_value(ValueType value);

    void accept(IVisitor& visitor) override;
};
