#include <iostream>
#include <vector>
#include <fstream>
#include "incluidos.hpp"

/*! \brief Parse long strings like "A+B+C<->D+E->G" into separated complexes (Feinberg definition)
 *  \param <sInput> Input string, this string will be split into sepparated "X->Y" reaction strings
 *  \return <vsOutput> By reference, this vector stores the resulting "X->Y" reaction strings properly ordered
 *
 *  When you run this function, it returns a vector of strings by reference, parse long strings like "A+B+C->D+E->G"
 *  into separated complexes (Feinberg definition) "A+B+C->D+E, "D+E->A+B+C" and so on.
 */


void orderReactionString(std::string sInput,std::vector<std::string>& vsOutput)
{
  
  std::cout << sInput << std::endl;
  
  std::vector< std::string > vsPatterns;
  
  vsPatterns.push_back("<->");
  vsPatterns.push_back("<=>");
    
  std::vector<std::string>* vsBuffer = new std::vector<std::string>;
  
 
  int i=0;
  
  for(int i=0;i!=vsPatterns.size();i++)
  {
    
    while(sInput.find(vsPatterns[i])<sInput.length())
    {
      
    /* The left side of sInput */
    std::string* sLTemp = new std::string(sInput.substr(0,sInput.find(vsPatterns[i])));
      
    /* The rigth side of sInput */
    std::string* sRTemp = new std::string(sInput.substr(sInput.find(vsPatterns[i])+vsPatterns[i].length()));
 
    /* Store the part of string into the vector */
    vsBuffer->push_back(*sLTemp);
    
    sInput=*sRTemp;
    
    if(sRTemp->find(vsPatterns[i])>sRTemp->length())
    {
      vsBuffer->push_back(*sRTemp);
    }
    
    delete(sRTemp);
    delete(sLTemp);
    }
  }
  
  for(int i=0;i<vsBuffer->size()-1;i++)
  {
    vsOutput.push_back(vsBuffer->at(i)+"->"+vsBuffer->at(i+1));
    vsOutput.push_back(vsBuffer->at(i+1)+"->"+vsBuffer->at(i));
  }
}
