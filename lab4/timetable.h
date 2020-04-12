
// Written by Hans de Nivelle, February 2019, for CSCI 152.

#ifndef TIMETABLE_INCLUDED
#define TIMETABLE_INCLUDED  1

#include <iostream>
#include <list>
#include <map>
#include <iomanip>

class timetable
{
   std::string algo; 
      // Name of algorithm used.

   std::list< double > version;
      // If you have a version number, you can put it here.

   std::map< size_t, double > times;
      // Maps input sizes to run times.

public: 
   timetable( ) = delete;  
      // There is no default constructor,
      // because you must give a name. 

   // Examples: timetable tab( "heapsort" );
   // timetable tab( "quicksort" { 1.0 } );

   timetable( const std::string& algo, const std::list< double > & version = { } )
      : algo{ algo },
        version{ version }
   { }

   timetable( const char* algo, const std::list< double > & version = { } )
      : algo{ std::string(algo) },
        version{ version } 
   { }

   void insert( size_t inputsize, double runtime )
   {
      times[ inputsize ] = runtime;
   }

   size_t size( ) const 
   {
      return times. size( ); 
   }

   void clear( ) 
   {
      times. clear( );
   }

   double totaltime( ) const
   {
      double t = 0;
      for( const auto& p : times )
         t += p. second;
      return t;
   }
   
   std::ostream& print( std::ostream& out ) const
   {
      out << "Performance table of " << algo;
      if( version. size( ))
      {
         out << " (version "; 
         for( auto p = version. begin( ); p != version. end( ); ++ p ) 
         {
            if( p != version. begin( ))
               out << "-";
            out << *p;
         } 
         out << ")";
      }
      out << " (inputsize/runtime in seconds):\n";
      out << std::scientific; 
      for( auto t : times )
      {
         out << "     " << t. first << "/";
         out << std::setprecision(4) << t. second;
      }
      out << "\n";
      return out; 
   }

};


inline std::ostream& operator << ( std::ostream& out, const timetable& t )
{
   return t. print( out );
}


#endif 


