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

  std::vector<std::string> vsSpecies;
  
  for(int k=0;k!=vsStringInput.size();k++)
  {
	  //getStringVector("+",vsStringInput[k],vsSpecies);
	  boost::algorithm::split(vsSpecies,vsStringInput[k],boost::algorithm::is_any_of("+"));
  }

  //std::cout << "species " << vsSpecies.size() << std::endl;

  //for(int k=0;k!=vsSpecies.size();k++)
  //{
  	//std::cout << k << " look " << vsSpecies[k] << std::endl; 
  //}
  
  
  for(int k=0;k!=vsSpecies.size();k++)
  {
    unStoichem(vsSpecies[k]);
  }
  
  for(int i=0;i<vsSpecies.size();i++)
  {   
    if(mSpecies.find(vsSpecies[i])==mSpecies.end())
    {
      /* This apply for C++ 11 standard :'( */
		//int iPos = mSpecies.size();
		//std::cout << vsSpecies[i] << "," << mSpecies.size() << std::endl;
		//mSpecies.emplace(vsSpecies[i],iPos);
		mSpecies.emplace(vsSpecies[i],mSpecies.size());
	    //mSpecies.insert( std::pair<std::string,int>(vsSpecies[i],mSpecies.size()));

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
  
  //getStringVector(sPattern,sInput,*vComplex);
  boost::algorithm::split(*vComplex,sInput,boost::algorithm::is_any_of(sPattern));
  getSpeciesMap(*vComplex,mSpecies);
  
  delete(vComplex);
}
