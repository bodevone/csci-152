
#include "stack.h"

// Use this method for all your reallocations:

stack::stack() :
    data(new double[5]),
    current_size(0),
    current_capacity(5)
{

}

stack::stack(const stack& s) :
    data(new double[s.current_capacity]),
    current_size(s.current_size),
    current_capacity(s.current_capacity)
{
  for (size_t i = 0; i < s.current_size; i++) {
    data[i] = s.data[i];
  }
}

const stack& stack::operator = ( const stack& s ) {
  //TO-DO:

  current_size = s.current_size;

  for (size_t i = 0; i < s.current_size; i++) {
    data[i] = s.data[i];
  }
  return *this;
}


stack::stack( std::initializer_list<double> init ) {
  for (int i = 0; i < init.size(); i++) {
    data[i] = init.begin()[i];
  }
}

void stack::push(double val) {
  //TO-DO: check size and capacity
  data[current_size] = val;
  ++current_size;
}

double stack::peek() const {

  return data[current_size - 1];
}

void stack::pop() {

  current_size--;
}

void stack::clear() {

  current_size = 0;
}

void stack::reset(size_t s) {

  current_size = s;
}

size_t stack::size() const {

  return current_size;
}

bool stack::empty() const {
  return (current_size == 0);
}


void stack::ensure_capacity( size_t c )
{
   if( current_capacity < c )
   {
      // New capacity will be the greater of c and
      // 2 * current_capacity.

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      double* newdata = new double[ c ];
      for( size_t i = 0; i < current_size; ++ i )
         newdata[i] = data[i];

      current_capacity = c;
      delete[] data;
      data = newdata;
   }
}

stack::~stack() {

  delete[] data;
}
