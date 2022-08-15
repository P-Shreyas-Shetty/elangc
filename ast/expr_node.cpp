#ifndef __EXPR_NODE_CPP__
#define __EXPR_NODE_CPP__

#include "ast.hpp"

// ABSTRACT class for EXpressions
// variants:
//  ADD<Expr, Expr>
//  SUB<Expr, Expr>
//  DIV<Expr, Expr>
//  MUL<Expr, Expr>
//  GT<Expr, EXpr>
//  GTE<Expr, Expr>
//  LT<Expr, Expr>
//  LTE<Expr, Expr>
//  EQ<Expr, Expr>
//  NEQ<Expr, Expr>
//  AND<Expr, Expr>
//  OR<Expr, Expr>
//  NOT<Expr>
//  BAND<Expr, Expr>
//  BOR<Expr, Expr>
//  COMPL<Expr>
//  XOR<Expr>
//  FNCALL<Expr..>
//  ALLOC<Expr>
//
class Expr : public ast::ASTNode {};

class UnaryNegExpr : Expr {
public:
  std::unique_ptr<Expr> in;

  UnaryNegExpr(Expr in) { this->in = std::make_unique<Expr>(in); }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "UnaryNeg {\n" +
           this->in->to_string(indent + 1) + "\n" + std::string(indent, ' ') +
           "}";
  }
};

class AddExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  AddExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Add { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class SubExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  SubExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Sub { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class MulExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  MulExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Mul { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class DivExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  DivExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Div { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class EqExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  EqExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Eq { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class NeqExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  NeqExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Neq { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class GtExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  GtExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Gt { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class GteExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  GteExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Gte { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class LtExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  LtExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Lt { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class LteExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  LteExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Lte { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class AndExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  AndExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "And { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class OrExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  OrExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Or { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class NotExpr : Expr {
public:
  std::unique_ptr<Expr> in;

  NotExpr(Expr in) { this->in = std::make_unique<Expr>(in); }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Not {\n" +
           this->in->to_string(indent + 1) + "\n" + std::string(indent, ' ') +
           "}";
  }
};

class BAndExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  BAndExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "BAnd { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class BOrExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  BOrExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "BOr { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class ComplExpr : Expr {
public:
  std::unique_ptr<Expr> in;

  ComplExpr(Expr in) { this->in = std::make_unique<Expr>(in); }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "Compl {\n" +
           this->in->to_string(indent + 1) + "\n" + std::string(indent, ' ') +
           "}";
  }
};

class BXorExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  BXorExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "BXor { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class RShiftExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  RShiftExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "RShift { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class RShiftExpr : Expr {
public:
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;

  RShiftExpr(Expr lhs, Expr rhs) {
    this->lhs = std::make_unique<Expr>(lhs);
    this->rhs = std::make_unique<Expr>(rhs);
  }

  std::string to_string(int indent = 0) {
    return std::string(indent, ' ') + "RShift { " + lhs->to_string(indent + 1) +
           ",\n" + rhs->to_string(indent + 1) + "\n" + std::string(indent, ' ');
  }
};

class FnCallExpr : Expr {
public:
  std::vector<std::unique_ptr<Expr>> args;
  ast::FnNode *fn;
  FnCallExpr(std::string name, std::vector<Expr> args) {}
};

#endif //__EXPR_NODE_CPP__
