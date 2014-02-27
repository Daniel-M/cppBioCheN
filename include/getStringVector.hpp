#include <iostream>
#include <string>
#include <vector>

#ifndef UN_STOICHEM
  #define UN_STOICHEM
  #include "unStoichem.hpp"
#endif

void getStringVector(std::string sPattern, std::string sInput, std::vector<std::string>& vStringOutput)
{
  if(sInput.rfind(sPattern)<sInput.length() )
  {
    /* The right side of sInput */
    std::string* sRTemp = new std::string(sInput.substr(sInput.rfind(sPattern)+sPattern.length()));
    
    /* The left side of sInput */
    std::string* sLTemp = new std::string(sInput.substr(0,sInput.rfind(sPattern)));
   
    /* Store the part of string into the vector */
    vStringOutput.push_back(*sRTemp);
    
    /* And that sir, is what we call recursion! 
     * I'll do a search along all the string so 
     * in the end i'll have the whole strings separated
     */
    getStringVector(sPattern,*sLTemp,vStringOutput);
    
    delete(sRTemp);
    delete(sLTemp);
  }
  else if(sInput.length()!=0 && sInput != "")
  {
    
    /* At this point should only rest the first part of the initial sInput
     * so is stored on the vector to return all the separated parts
     */
    vStringOutput.push_back(sInput);
  }
  
}