#include "ast.hpp"

constexpr size_t REF_SIZE = 0;
// Base class for all Nodes
class ASTNode {
public:
  virtual std::string to_string(size_t indent = 0);
};
