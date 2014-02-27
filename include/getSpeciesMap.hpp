#include <iostream>
#include <string>
#include <vector>
#include <map>

#ifndef GET_STRING_VECTOR
  #define GET_STRING_VECTOR
  #include "getStringVector.hpp"
#endif

#ifndef UN_STOICHEM
  #define UN_STOICHEM
  #include "unStoichem.hpp"
#endif

void getSpeciesMap(std::vector<std::string> vStringInput, std::map<std::string,int> &mSpecies)
{
  

  std::vector<std::string> vSpecies;
  
  for(int k=0;k!=vStringInput.size();k++)
  {
    getStringVector("+",vStringInput[k],vSpecies);
  }
  
  
  for(int k=0;k!=vSpecies.size();k++)
  {
    unStoichem(vSpecies[k]);
  }
//   /* For 'debug' to see whats happening */
//   for(int i=0;i<vSpecies.size();i++)
//   {
//     cout << " Tengo a " << i << " almacenando a " << vSpecies[i] << endl;
//   }
  
  for(int i=0;i<vSpecies.size();i++)
  {   
    if(mSpecies.find(vSpecies[i])==mSpecies.end())
    {
      /* This apply for C++ 11 standard :'( */
//       mSpecies.emplace(vSpecies[i],mSpecies.size()+1);
      mSpecies.insert( std::pair<std::string,int>(vSpecies[i],mSpecies.size()+1));

    }
   }
}


void getSpeciesMap(std::string sPattern, std::string sInput, std::map<std::string,int> &mSpecies)
//(std::vector<std::string> vStringInput, std::map<std::string,int> &mSpecies)
{
  std::vector<std::string> *vComplex = new std::vector<std::string>;
  
  getStringVector(sPattern,sInput,*vComplex);
  getSpeciesMap(*vComplex,mSpecies);
  
  delete(vComplex);
}