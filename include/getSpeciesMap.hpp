//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>

#include "incluidos.hpp"

/**\brief maps the chemical species given a vector containing strings of complexes
 *
 * \param[in] vsStringInput Vector containing the chemical complexes.
 * \param[out] mSpecies a map that stores the chemical species contained on \a vsStringInput.
 * \note mSpecies is modified by reference.
 */
void getSpeciesMap(std::vector<std::string> vsStringInput, std::map<std::string,int> &mSpecies)
{

  std::vector<std::string> vSpecies;
  
  for(int k=0;k!=vsStringInput.size();k++)
  {
    getStringVector("+",vsStringInput[k],vSpecies);
  }
  
  
  for(int k=0;k!=vSpecies.size();k++)
  {
    unStoichem(vSpecies[k]);
  }
  
  for(int i=0;i<vSpecies.size();i++)
  {   
    if(mSpecies.find(vSpecies[i])==mSpecies.end())
    {
      /* This apply for C++ 11 standard :'( */
		mSpecies.emplace(vSpecies[i],mSpecies.size()+1);
	  //mSpecies.insert( std::pair<std::string,int>(vSpecies[i],mSpecies.size()+1));

    }
   }
}

/**
 * \overload This function maps chemical species given a string as input.
 */
void getSpeciesMap(std::string sPattern, std::string sInput, std::map<std::string,int> &mSpecies)
//(std::vector<std::string> vsStringInput, std::map<std::string,int> &mSpecies)
{
  std::vector<std::string> *vComplex = new std::vector<std::string>;
  
  getStringVector(sPattern,sInput,*vComplex);
  getSpeciesMap(*vComplex,mSpecies);
  
  delete(vComplex);
}
