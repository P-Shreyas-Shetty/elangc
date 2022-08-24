#ifndef __AST_CONTEXT_CPP__
#define __AST_CONTEXT_CPP__
#include "ast.hpp"

class Context {
public:
  std::unordered_map<std::string, std::shared_ptr<ast::FnNode>> functions;
  std::unordered_map<std::string, std::shared_ptr<ast::VarNode>> variables;
  std::shared_ptr<Context> parent_ctx;
  bool has_parent_ctx;

  Context(std::shared_ptr<Context> parent_ctx) {
    this->parent_ctx = parent_ctx;
    this->has_parent_ctx = true;
  }

  Context() {
    this->has_parent_ctx = false;
  }

  std::shared_ptr<ast::FnNode> get_fn(std::string name) {
    auto fn_iter{functions.find(name)};

    if (fn_iter != std::end(functions)) {
      auto fn{fn_iter->second};
      return fn;
    } else {
      if (has_parent_ctx) {
        return parent_ctx->get_fn(name);
      } else {
        throw  ast::CompilerError("Error");
      }
    }
  }
};

#endif //__AST_CONTEXT_CPP__