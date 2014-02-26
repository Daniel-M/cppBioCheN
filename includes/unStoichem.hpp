#include <string>
#include <iomanip>
#include <algorithm>


int unStoichem(std::string& sInput)
{
  std::string sCoeff;
   
  if(isdigit ( sInput.at ( 0 ) ))
  {
    int i(0);
    
    while(isdigit ( sInput.at ( i ) ))
    {
      i++;
    }
    
    sCoeff=sInput.substr(0,i).c_str();
    sInput=sInput.substr(i,sInput.length());
    
    return atoi(sCoeff.c_str());    
  }
  else
  {
    sInput=sInput;
    return 1;
  }
}