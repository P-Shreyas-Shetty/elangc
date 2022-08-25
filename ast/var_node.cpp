#ifndef __VAR_NODE_CPP__
#define __VAR_NODE_CPP__

#include "ast.hpp"

class VarNode : public ast::ASTNode {
    public:
    ast::Type ty;
    std::string name;
};
#endif //__VAR_NODE_CPP__