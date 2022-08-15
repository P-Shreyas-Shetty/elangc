#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
namespace ast {
#include "ast_context.cpp"
#include "base_node.cpp"
#include "expr_node.cpp"
#include "function_node.cpp"
#include "types.cpp"
#include "var_node.cpp"
} // namespace ast
#endif // __AST_HPP__