#ifndef __BASE_NODE_CPP__
#define __BASE_NODE_CPP__

#include "ast.hpp"

// Base class for all Nodes
class ASTNode {
public:
  virtual std::string to_string(size_t indent = 0);
};

class CompilerError : public std::runtime_error {
  std::string what_message;

public:
  const char *what() { return what_message.c_str(); }
};

#endif //__BASE_NODE_CPP__