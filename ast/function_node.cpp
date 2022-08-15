#ifndef __FUNCTION_NODE_CPP__
#define __FUNCTION_NODE_CPP__

#include "ast.hpp"

// Function node type
class FnNode : public ast::ASTNode {
  typedef struct {
    std::string name;
    ast::Type *ty;
    // std::optional<ast::Expr> def;
  } ArgTypeDefaultTriple;

  std::string name;
  ArgTypeDefaultTriple args;
  ast::Type *rtype;
  // TODO: Define this
};

#endif // __FUNCTION_NODE_CPP__