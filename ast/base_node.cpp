#ifndef __BASE_NODE_CPP__
#define __BASE_NODE_CPP__

#include "ast.hpp"

// Base class for all Nodes
class ASTNode {
public:
  virtual std::string to_string(size_t indent = 0);
};

class CompilerError  {
	public:
  std::string msg;

  CompilerError(std::string msg) {
    this->msg = msg;
  }
       
};

#endif //__BASE_NODE_CPP__