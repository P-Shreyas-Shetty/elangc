#ifndef __AST_CONTEXT_CPP__
#define __AST_CONTEXT_CPP__
#include "ast.hpp"

class Context {
public:
  std::unordered_map<std::string, std::shared_ptr<ast::FnNode>> functions;
  std::unordered_map<std::string, std::shared_ptr<ast::VarNode>> variables;
  std::optional<std::shared_ptr<Context>> parent_ctx;

  std::shared_ptr<ast::FnNode> get_fn(std::string name) {
    auto fn_iter{functions.find(name)};

    if (fn_iter != std::end(functions)) {
      auto fn{fn_iter->second};
      return fn;
    } else {
      if (parent_ctx.has_value()) {
        return parent_ctx.value()->get_fn(name);
      } else {
        throw new ast::CompilerError("");
      }
    }
  }
};

#endif //__AST_CONTEXT_CPP__