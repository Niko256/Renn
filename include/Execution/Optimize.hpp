#pragma once

#include "../Ast/visitor.hpp"

namespace renn::execution {

class Optimizer : public ast::AstVisitor {};

}  // namespace renn::execution
