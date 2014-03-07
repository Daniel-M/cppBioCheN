#include <iostream>
#include <string>
#include <vector>
#include "incluidos.hpp"

/**\brief Get a vector of strings sepparated by a pattern
 *
 * \param[in] sPattern The string of the pattern to be found.
 * \param[in] sInput An input string to be searched for the pattern \a sPattern.
 * \param[out] vStringOutput The vector that will store the substrings of \a sInput separated by \a sPattern.
 * \note vsStringOutput is modified by reference.
 */
void getStringVector(std::string sPattern, std::string sInput, std::vector<std::string>& vStringOutput)
{
	//boost::algorithm::split(vStringOutput,sInput,boost::algorithm::is_any_of(sPattern));
	//}



	//{
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
