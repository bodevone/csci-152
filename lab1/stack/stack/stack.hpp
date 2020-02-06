//
//  stack.hpp
//  stack
//
//  Created by Alibi Shalgymbay on 2/7/20.
//  Copyright © 2020 Alibi Shalgymbay. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <iostream>
#include <initializer_list>

class stack
{
   size_t current_size;
   size_t current_capacity;

   double* data;
      // INVARIANТ: has been allocated with size current_capacity.
      // 0 <= current_size <= current_capacity.

   void ensure_capacity( size_t c );
      // Ensure that stack has capacity of at least c.
      // This function is given, so you don't have to write it.

public:
   stack( );
      // Constructs empty stack.

   stack( const stack& s );

   ~stack( );

   const stack& operator = ( const stack& s );

   stack( std::initializer_list<double> init );
      // So that you can write s = { 1,2,3 };
      // You can use init. size( ) to see the size, and
      // for( double d : init ) to go through all
      // elements in the initializer_list.

   void push( double d );

   void pop( );

   void clear( );

   void reset( size_t s );

   double peek( ) const;

   size_t size( ) const;

   bool empty( ) const;

   friend std::ostream& operator << ( std::ostream& , const stack& );
};

std::ostream& operator << ( std::ostream& , const stack& );



#endif /* stack_hpp */
