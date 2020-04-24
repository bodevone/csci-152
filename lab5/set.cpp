/*
 * set.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: benja
 */


#include "set.h"


bool set::simp_insert( const std::string& s )
{
  int index = hash(s) % buckets.size();
  std::list<std::string> bucket = buckets[index];

  for (std::string b : bucket)
    if (eq(b, s)) return false;

  buckets[index].push_back(s);
  set_size++;
  return true;
}

std::ostream& set::print( std::ostream& out ) const
{
  for (size_t i = 0; i < buckets.size(); ++i)
  {
    std::list<std::string> bucket = buckets[i];
    out << "bucket [ " << i << " ] = ";
    out << "{";
    bool notfirst = false;
    for (auto b : bucket)
    {
      if (notfirst)
        out << ",";
      notfirst = true;
      out << " " << b;
    }
    out << " }" << std::endl;
  }
  return out;
}

bool set::contains( const std::string& s ) const
{
  int index = hash(s) % buckets.size();
  std::list<std::string> bucket = buckets[index];

  for (auto b : bucket)
    if (eq(b, s)) return true;
  return false;
}

bool set::remove( const std::string& s )
{
  int index = hash(s) % buckets.size();
  std::list<std::string> bucket = buckets[index];

  for (auto b : bucket)
  {
    if (eq(b, s))
    {
      buckets[index].remove(b);
			set_size--;
      return true;
    }
  }
  return false;
}

void set::clear( )
{
  for (size_t i = 0; i < buckets.size(); ++i)
		buckets[i].clear();
	set_size = 0;
}

void set::rehash( size_t newbucketsize )
{
  if( newbucketsize < 4 )
    newbucketsize = 4;
  std::vector< std::list< std::string >> newbuckets = std::vector< std::list< std::string >> ( newbucketsize );

  for (size_t i = 0; i < buckets.size(); ++i)
  {
    std::list<std::string> bucket = buckets[i];

    for (auto b : bucket)
    {
      int index = hash(b) % newbucketsize;
      newbuckets[index].push_back(b);
    }
  }

  std::swap( buckets, newbuckets );
}

bool set::insert( const std::string& s )
{
  bool isinserted = simp_insert(s);
  if (loadfactor() > max_load_factor)
  {
    size_t newsize = buckets.size() * 2;
    rehash(newsize);
  }
	return isinserted;
}

set::set( std::initializer_list<std::string > init )
  : set_size{ 0 },
    max_load_factor{ 3.0 },
    buckets{ std::vector< std::list< std::string >> ( 4 ) }
{
  for (std::string b : init)
    insert(b);
}


std::ostream& set::printstatistics( std::ostream& out ) const
{
  out << "set size =            " << size( ) << "\n";
  out << "load factor =         " << loadfactor( ) << " ( max = " << max_load_factor << " )\n";
  out << "standard deviation =  " << standarddev( ) << "\n";
  return out;
}
