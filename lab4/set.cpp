
#include "set.h"


void print( std::ostream& out, const treenode* n, size_t indent )
{

   for( size_t i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


// both the upperbound and the lowerbound are strict,
// we use pointers, so that they can be absent. 

void checkbetween( const treenode* n, 
                   const int* lowerbound, const int* upperbound ) 
{
   while(n) 
   {
      if( lowerbound && *lowerbound >= n -> val )
      {
         std::cout << "value " << ( n -> val );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         std::abort( );
      }

      if( upperbound && n -> val >= *upperbound )
      {
         std::cout << "value " << ( n -> val );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         std::abort( );
      }

      checkbetween( n -> left, lowerbound, &( n -> val ));
      lowerbound = & ( n -> val );
      n = n -> right;
   }
} 


void deallocate( treenode* n )
{
   while(n)
   {
      deallocate( n -> left );
      treenode* bye = n;
      n = n -> right;
      delete bye;
   }
}


void writecopy( treenode** to, treenode* from )
{
   while( from )
   {
      *to = new treenode{ from -> val };

      writecopy( & (*to) -> left, from -> left );
      to = & (*to) -> right;
      from = from -> right;
   }
}


void set::checksorted( ) const
{
   ::checkbetween( tr, nullptr, nullptr );
}


std::ostream& set::print( size_t indent, std::ostream& out ) const
{
   ::print( out, tr, indent );
   return out;
}

size_t log_base2( size_t t )
{
   size_t mult = 2;
   size_t value = 0;
   while ( mult <= t )
   {
      mult = mult * 2;
      value++;
   }
   return value;
}

const treenode* find( const treenode *n, int i )
{
   if (n == nullptr) return n;
   else if (n->val == i) return n;
   else if (n->val > i) return find(n->left, i);
   else return find(n->right, i);
}

treenode** find( treenode** n, int i )
{
   if (*n == nullptr) return n;
   else if ((*n)->val == i) return n;
   else if ((*n)->val > i) return find(&(*n)->left, i);
   else return find(&(*n)->right, i);
}

bool set::insert( int i )
{
   treenode** n = find(&tr, i);
   if (*n == nullptr) {
      *n = new treenode(i);
      return true;
   } else {
      return false;
   }
}

bool set::contains( int i ) const
{
   if(find(tr, i) == nullptr) return false;
   else return true;
}

treenode* removerightmost( treenode** from )
{
   if (*from == nullptr) return *from;
   if ((*from)->right==nullptr) {
      treenode* temp = *from;
      *from = (*from)->left;
      return temp;
   }
   return removerightmost(&(*from)->right);
}

bool set::remove( int i )
{
   treenode** n = find(&tr, i);
   if (*n == nullptr) return false;
   if ((*n)->left == nullptr && (*n)->right == nullptr) {
      delete *n;
      *n = nullptr;
   } else if ((*n)->right == nullptr) {
      treenode* temp = *n;
      *n = (*n)->left;
      delete temp;
   } else {
      treenode* right = removerightmost(&(*n)->left);
      if (right == nullptr) {
         treenode* temp = *n;
         *n = (*n)->right;
         delete temp;
      } else {
         (*n)->val = right->val;
         delete right;
         right = nullptr;
      }
   }
   return true;
}

size_t size( const treenode* n )
{
   if (n == nullptr) return 0;
   return size(n->left) + size(n->right) + 1;
}

void clear( treenode* n )
{
   if (n != nullptr) {
      clear(n->left);
      clear(n->right);
      delete n;
   }
}

void set::clear( ) {
   ::clear(tr);
   tr = nullptr;
}

bool set::isempty(  )
{
   return tr == nullptr;
}

size_t height( const treenode* n )
{
   if (n == nullptr) return 0;
   return std::max(height(n->left), height(n->right)) + 1;
}

