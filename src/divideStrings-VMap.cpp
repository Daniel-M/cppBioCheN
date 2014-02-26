// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <iomanip>
// #include <algorithm>
#include "incluidos.hpp"

using namespace std;

int main(int argc, char **argv)
{
  string sTest(argv[3]);
  string palabra(argv[2]);
  string patronF(argv[1]);
  string patronS("+");
  
  std::vector<std::string> vComplex;


  std::map<std::string,int> mSpecies;
  std::map<std::string,int>::iterator iTmSpecies;
  
 
  cout << " Los patrones son " << patronF << " long= " << patronF.length()  << " Y " << patronS << endl;
  cout << " La palabra fue \'" << palabra << "\'" << " long= " << palabra.length() << endl;
  
//   cout << " Input " << palabra.length() << " lfind " << palabra.rfind(patronF) << " rfind " << palabra.rfind(patronF) << endl;
  
//   getStringVector(patronF,palabra,vComplex);
//   
//   
//   for(int i=0;i<vComplex.size();i++)
//   {
//     cout << " Tengo a " << i << " almacenando a " << vComplex[i] << endl;
//   }
// 
// //   getSpeciesMap(vComplex,mSpecies);
  
  getSpeciesMap(patronF,palabra,mSpecies);
  
  for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
  {
    std::cout << " Key " << iTmSpecies->first << " Value " << iTmSpecies->second << std::endl;
  }

  return 0;
}