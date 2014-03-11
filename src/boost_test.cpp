//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <cmath>

//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>

#include "incluidos.hpp"
//#include "getSimpleReactions.hpp"
//#include "overloadedMatrix.hpp"

using namespace std;

int main(void)
{
	std::fstream fsInput;
    fsInput.open("text.txt",std::fstream::in);
    
    std::fstream fsOutput;
    fsOutput.open("text-parsed.txt",std::ios::in | std::ios::out | std::ios::trunc);
    
    std::vector<std::string> vsSimpleReactions;
    
    std::map<std::string,int> mSpecies;
    std::map<std::string,int>::iterator iTmSpecies;
    
	std::string sLine;
    
    if(fsInput.is_open() && fsOutput.is_open())
    {
        
        while(fsInput.eof()!=true)
        {
            std::getline(fsInput,sLine);
            
            if(sLine!="")
            {
				//std::cout << sLine << std::endl;
                getSimpleReactions(sLine,vsSimpleReactions);
            }
        }
        
        fsInput.close();
        
        
        for(int i=0;i<vsSimpleReactions.size();i++)
        {
            fsOutput << vsSimpleReactions[i] << std::endl;
        }
        
        fsOutput.seekg(fsOutput.beg);
        
        while(fsOutput.eof()!=true)
        {
            std::getline(fsOutput,sLine);
            
            if(sLine!="")
            {
				//getSpeciesMap("->",sLine,mSpecies);
				getSpeciesMap(">",sLine,mSpecies);
            }
        }
        
        for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
        {
            std::cout << " Key " << iTmSpecies->first << " Value " << iTmSpecies->second << std::endl;
        }
        
        
    }
  
  boost::numeric::ublas::matrix<int> cN;
    
  getReactionMatrix(vsSimpleReactions,mSpecies,cN);
  
  std::cout << "\n";
  std::cout << "\n";
  std::cout << cN;
  std::cout << "\n";
	

  getMassActionLawKinetics(mSpecies,cN);




  return 0;
  



/***********************************************************/
/***********************************************************/
/*********** Old version of this file is down***************/
/***********************************************************/
/***********************************************************/
/***********************************************************/

/*
	std::string sInput("A +b+l-> j+l<=>p<->3e<->3K+t");
	std::vector <std::string> vsSimpleReactions;//
	
	getSimpleReactions(sInput,vsSimpleReactions);//

	for(int i=0;i<vsSimpleReactions.size();i++)
	{
		std::cout << vsSimpleReactions[i] << std::endl;
	}
*/
}
