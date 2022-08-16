# elangc
An attempt at writing a compiler

## General syntax

```
//This is comment
//variable declaration

let x: i32 = 0; //variable MUST be initialized with some value
let y = 0; //type inference (atleast in simpler cases)

let mut z: i32 = 42; //mutable variable

let xref: &i32 = &x; //reference type

let s = "Hello"; //string literal

//Heap allocation
let h: &str = new "Hello"; //Heap allocation isdone with `new`
del h;               //clear heap allocated ref. Maybe not needed if GC is added later

//function def
fn f(x: i32)->i32 {
  return x+1;
}

//function that takes mutable reference
fn increment(x: &mut i32) {
  x = x+1;
}

//Arrays
let k: [i32; 5] = [0; 5]; //All are initialized to 0
let k1: [i32; 3] = {1,2,3}; //Values set explicitely

k1[0] = 42; //Modify by index

//user defined struct
struct Triple {
  x: i32,
  y: i32,
  z: i32,
}

//Methods 
impl Triple {

  fn first(&self)->i32 {
    return self.x;
  }
  
  fn set_x(&mut self, x_new) {
    self.x = x_new;
  }
}

//Value type of struct
let s = Triple {x: 1, y:2, z:3};

//heap allocation of the struct
//The reference here is mutable
let sref: &mut Triple = new Triple {x:3, y:2, z:4};

sref.set_x(9); //Method call

del sref; //frees heap & deletes sref variable
