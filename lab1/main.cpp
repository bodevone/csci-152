#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "stack.h"

// This is part of an evaluator for expressions in RPN.
// If you implemented stack correctly, it will work.

// Is s an operator with one argument?

bool isoperator1( const std::string& s )
{
   return s == "exp" || s == "log" || s == "sqrt";
}

// Is s an operator with two arguments?

bool isoperator2( const std::string& s )
{
   return s == "+" || s == "-" || s == "*" || s == "/" ||
          s == "==" || s == "!=";
}

// Apply an operator with one argument:

double apply1( const std::string& s, double d1 )
{
   // std::cout << "applying " << s << " on " << d1 << "\n";

   if( s == "exp" ) return exp(d1);
   if( s == "log" ) return log(d1);
   if( s == "sqrt" ) return sqrt(d1);

   std::abort( );  // Unreachable, if program written correctly.
}

// Apply an operator with two arguments:

double apply2( const std::string& s, double d1, double d2 )
{
   // std::cout << "applying " << s << " on " << d1 << " and " << d2 << "\n";

   if( s == "+" ) return d1 + d2;
   if( s == "-" ) return d1 - d2;
   if( s == "*" ) return d1 * d2;
   if( s == "/" ) return d1 / d2;
   if( s == "==" ) return d1 == d2;
   if( s == "!=" ) return d1 != d2;

   std::abort( );  // Unreachable, if written well.
}


double makedouble( const std::string& s )
{
   return atof( s. c_str( ));
}

// Evaluate an expression in RPN:

double rpn( const std::vector<std::string> & expr )
{
   stack st;

   for( const auto& e : expr )
   {
      if( isoperator2( e ))
      {
         if( st. size( ) < 2 )
            throw std::runtime_error( "less than two numbers on stack" );

         double d2 = st. peek( ); st. pop( );
         double d1 = st. peek( ); st. pop( );

         st. push( apply2( e, d1, d2 ));
      }
      else
      {
         if( isoperator1(e))
         {
            if( st. size( ) < 1 )
               throw std::runtime_error( "no number on stack" );

            double d1 = st. peek( ); st. pop( );
            st. push( apply1( e, d1 ));
         }
         else
            st. push( makedouble( e ));
      }
      std::cout << e << " => " << st << "\n";
   }

   if( st. size( ) != 1 )
      throw std::runtime_error( "expression is not well-formed" );

   return st. peek( );
}

void teststack( ) {
  stack s1 = { 1, 2, 3, 4, 5 };
  stack s2 = s1; // Copy constructor.
  
  for( unsigned int j = 0; j < 30; ++ j ) s2. push( j * j );

  std::cout << s2 << "\n";

  s1 = s2; // Assignment.
  s1 = s1; // Self assignment.

  s1 = { 100,101,102,103 };
    // Works because the compiler inserts constructor and
    // calls assignment with the result.
  std::cout << s1 << "\n";
}

int main( int argc, char* argv [ ] )
{
  teststack();

   // If your stack was implemented correctly, this example from
   // wikipedia will work. The outcome is 5.

   // double d = rpn(
   //    { "15", "7", "1", "1", "+", "-", "/", "3", "*",
   //       "2", "1", "1", "+", "+", "-" } );
   //
   // std::cout << "outcome is " << d << "\n";
   //
   // // sqrt(2) * sqrt(2) = 2.
   //
   // d = rpn( { "2", "sqrt", "2", "sqrt", "*" } );
   // std::cout << "outcome is " << d << "\n";

   return 0;
}
