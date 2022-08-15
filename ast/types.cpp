#inlude "ast.hpp"

enum class BaseTypeEnum {
  Int8,
  Int16,
  Int32,
  Int64,
  Int128,
  UInt8,
  UInt16,
  UInt32,
  UInt64,
  UInt128,
  Float32,
  Float64,
  Float128,
  Str,
  Bool
};

// Variants for Types
// This enum is used for some kind of reflection mechanism
enum class TypeClassVariant { BUILTIN, REF, OPTREF, ARRAY, STRUCT };

// Abstract class for all Types
class Type : public ASTNode {
public:
  TypeClassVariant type;
  virtual size_t get_size();
};

// All builtin types are represented with this type
class BuiltinType : public Type {
public:
  BaseTypeEnum t;

  BuiltinType(BaseTypeEnum t_) {
    this->t = t_;
    this->type = TypeClassVariant::BUILTIN;
  }

  size_t get_size() {
    switch (t) {
    case BaseTypeEnum::Bool:
      return 1;
    case BaseTypeEnum::Float128:
      return 16;
    case BaseTypeEnum::Float64:
      return 8;
    case BaseTypeEnum::Float32:
      return 4;
    case BaseTypeEnum::Int8:
      return 1;
    case BaseTypeEnum::Int16:
      return 2;
    case BaseTypeEnum::Int32:
      return 4;
    case BaseTypeEnum::Int64:
      return 8;
    case BaseTypeEnum::Int128:
      return 16;
    case BaseTypeEnum::UInt8:
      return 1;
    case BaseTypeEnum::UInt16:
      return 2;
    case BaseTypeEnum::UInt32:
      return 4;
    case BaseTypeEnum::UInt64:
      return 8;
    case BaseTypeEnum::UInt128:
      return 16;
    case BaseTypeEnum::Str:
      return REF_SIZE; // for now, pointer types are just 0
    }
  }

  std::string to_string() {
    switch (t) {
    case BaseTypeEnum::Bool:
      return "bool";
    case BaseTypeEnum::Float128:
      return "f128";
    case BaseTypeEnum::Float64:
      return "f64";
    case BaseTypeEnum::Float32:
      return "f32";
    case BaseTypeEnum::Int8:
      return "i8";
    case BaseTypeEnum::Int16:
      return "i16";
    case BaseTypeEnum::Int32:
      return "i32";
    case BaseTypeEnum::Int64:
      return "i64";
    case BaseTypeEnum::Int128:
      return "i128";
    case BaseTypeEnum::UInt8:
      return "u8";
    case BaseTypeEnum::UInt16:
      return "u16";
    case BaseTypeEnum::UInt32:
      return "u32";
    case BaseTypeEnum::UInt64:
      return "u64";
    case BaseTypeEnum::UInt128:
      return "u128";
    case BaseTypeEnum::Str:
      return "&str"; // for now, pointer types are just 0
    }
  }
};

// Reference Type
class RefType : public Type {
public:
  Type *base_type;

  RefType(Type *base_type) {
    this->base_type = base_type;
    this->type = TypeClassVariant::REF;
  }
  size_t get_size() { return REF_SIZE; }
  std::string to_string() { return "&" + base_type->to_string(); }
};

// Nullable reference
class OptRef : public Type {
public:
  Type *base_type;
  OptRef(Type *base_type) {
    this->base_type = base_type;
    this->type = TypeClassVariant::OPTREF;
  }
  size_t get_size() { return REF_SIZE + 1; }
  std::string to_string() { return "?" + base_type->to_string(); }
};

// Refers to array type
class ArrayType : public Type {
public:
  Type *base_type;
  size_t size;
  ArrayType(Type *base_type, size_t size) {
    this->base_type = base_type;
    this->size = size;
    this->type = TypeClassVariant::ARRAY;
  }
  size_t get_size() { return size * base_type->get_size(); }
  std::string to_string() {
    return "[" + base_type->to_string() + "; " + std::to_string(size) + "]";
  }
};

// User defined custom struct type
class Struct : public Type {
public:
  typedef struct {
    std::string name;
    Type *t;
    // std::optional<Expr> default_;
  } member_t;
  std::vector<member_t> members;
  std::string name;

  Struct(std::string name, std::vector<member_t> ms) {
    this->members = ms;
    this->name = name;
    this->type = TypeClassVariant::STRUCT;
  }

  size_t get_size() {
    size_t s = 0;
    for (auto m : members) {
      s += m.t->get_size();
    }
    return s;
  }

  std::string to_string() {
    std::string ret = "struct " + name + "{";
    for (auto &m : members) {
      ret += m.name + ": " + m.t->to_string() + ", ";
    }
    ret += "}";
    return ret;
  }
};
c
