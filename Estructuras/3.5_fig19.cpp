#include <iostream>
#include <vector> 
#include <list>

using namespace std;
template <typename Type> void Write(Type &ds, ostream &os)
{
  typename Type::iterator iter = ds.begin();
  for( ; iter != ds.end() ; iter++ )
    os << *iter << "\n";
}


int main(int argc, char* argv[])
{
  list<float> mylist;
  vector<float> myvector;
  for( int i = 0 ; i < 10 ; i++ )
  {
    mylist .push_back( i );
    myvector.push_back(i+50);
  }
  Write(mylist, cout);
  Write(myvector, cout);
  return 0;
}
