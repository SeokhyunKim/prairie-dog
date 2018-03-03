#include <cereal/archives/xml.hpp>
#include <iostream>
#include <fstream>

struct MyData
{
  bool   b;
  double d;

  template <class Archive>
  void serialize( Archive & ar )
  {
    ar( b, d );
  }
};

int main()
{
  int i1, i2, i3, i4;
  MyData md;

  {
    std::ifstream is("data.xml");
    cereal::XMLInputArchive ar(is);

    // NVP doesn't match expected value, perform a search
    ar( cereal::make_nvp("myData", md) );

    ar( i4 );                           // cereal continues from node it found using search
    ar( cereal::make_nvp("var1", i1) ); // new search re-positions at node var1
    ar( i2, i3 );                       // continue from location of last search

                                                // next value read would be 'myData'
    ar( cereal::make_nvp("doesNotExist", i1) ); // throws an exception: NVP not found
  }

  return 0;
}
