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
class Expr : public ASTNode {};

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
c
