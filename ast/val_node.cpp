#ifndef __VAL_NODE_CPP__
#define __VAL_NODE_CPP__

#include "ast.hpp"

class val_node: public ast::ASTNode {
    public:
    ast::Type ty;
    
};

#endif //__VAL_NODE_CPP__