
#include <random>

#include "set.h"
#include "timetable.h"
#include "timer.h"

int main( int argc, char* argv[ ] )
{
   std::cout<<log_base2(16);

   set small;    // A small test tree.

   std::cout << small. height( ) << "\n";
   small. insert( 100 ); 
   std::cout << small. height( ) << "\n"; 
   small. insert( 200 ); 
   std::cout << small. height( ) << "\n";
   small. insert( 121 );
   std::cout << small << "\n";
   std::cout << small. height( ) << "\n";

   small. clear( );
   std::cout << "this is the tree: " << small << "\n";
   set small3 = small; 
   std::cout << small3 << "\n";

 
   std::cout << small. contains( 44 ) << "\n";
   std::cout << small. contains( 12 ) << "\n";
      // Or not to be, that's the question. 

   small. insert( 112 );
   std::cout << small. contains( 112 ) << "\n";

   small. insert( 120 );

   small. insert( 130 );
   small. insert( 125 );
   std::cout << small<< "\n";
   small. insert( 131 ); 
   std::cout << small<< "\n";
   small. insert( 121 );
   small. checksorted( );

   std::cout << small<< "\n";
   std::cout << "before removal\n";
   std::cout << small<< "\n";

   small. remove( 125 ); 
   std::cout << "after removal\n";
   std::cout << small << "\n";  
#if 0


   std::cout << small << "\n"; 
   std::cout << small. size( ) << "\n";
   std::cout << "Height is " << small. height( );
   
   std::cout << " should be approximately " << log_base2( small. size( )) << "\n";
      // If the numbers differ much, the tree is badly balanced. 

   auto small2 = small; // Copy constructor. 
   std::cout << small2 << "\n";

   std::cout << small2. size( ) << "\n";
   std::cout << small2. height( ) << "\n";
   small2 = small;      // Assignment.
   small = small;       // Self assignment.

   timetable tab( std::string( "set" ));

   for( size_t s = 1000; s < 1500000; s = 2 * s ) 
   {
      set someset1;

      timer tt; 
      size_t nr = 0;
      for( size_t k = 0; k != s; ++ k )
      {
         nr += someset1. insert( 100 + rand( ) );
         nr += someset1. insert( 200 + rand( ) );
         // someset1.checksorted( ); 
      }

     
      auto someset2 = someset1;

      if( nr != someset2. size( )) 
      {
         std::cout << "nr = " << nr << "\n";
         std::cout << "size( ) = " << someset2. size( ) << "\n"; 
         throw std::runtime_error( "counting went wrong" );
      }

      // Don't use size( )! It is O(n), and will mess up your performance. 

      while( !someset2. isempty( )) 
      {
         nr -= someset2. remove( someset2. top( ));  
      }

      if( nr != 0 || someset2. size( ) != 0 )
      {
         std::cout << "nr = " << nr << "\n";
         std::cout << "someset2. size( ) = " << someset2. size( ) << "\n";
         throw std::runtime_error( "counting went wrong" ); 
      }
      tab. insert( s, tt. time( )); 
   } 
  
   std::cout << tab << "\n"; 
   std::cout << "totaltime " << tab. totaltime( ) << "\n";
# endif
}


