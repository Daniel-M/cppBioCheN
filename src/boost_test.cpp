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

std::string KinF(std::string sSimpleReaction,std::map<std::string,int> mSpecies)
{
	std::map<std::string,int>::iterator iTmSpecies;
		
	std::vector<int> viReactantsVector;

	getReactantsVector(sSimpleReaction,mSpecies,viReactantsVector);
	
	std::string sVarName("x");
	std::string sPow("pow");
	

	std::string sKinect("");


	for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
	{
		
		if(viReactantsVector[iTmSpecies->second] > 1)
		{
			std::string *sIndex = new std::string(numberToString(iTmSpecies->second,true));
			std::string *sVar = new std::string(sVarName+"[" + *sIndex + "]");
			std::string *sExponent = new std::string(numberToString(viReactantsVector[iTmSpecies->second],true));
			sKinect = sKinect + sPow + "(" + *sVar + "," + *sExponent + ")";

			delete(sIndex);
			delete(sVar);
			delete(sExponent);

		}
		else if (viReactantsVector[iTmSpecies->second] == 1)
		{
			std::string *sIndex = new std::string(numberToString(iTmSpecies->second,true));
			std::string *sVar = new std::string(sVarName+"[" + *sIndex + "]");
			sKinect = sKinect + *sVar;
		
			delete(sIndex);
			delete(sVar);
		}

		if(iTmSpecies->second < mSpecies.size() && viReactantsVector[iTmSpecies->second] >= 1)
		{
			sKinect += "*";
		}
	}

		//return sKinect;
	return sKinect.substr(0,sKinect.size()-1);
}

std::vector<std::string> /*void*/ KinPut(std::vector<std::string> vsSimpleReactions, std::map<std::string,int> mSpecies, std::map<std::string,std::string>& mKinetics)
{

	std::vector<std::string> vsR;
	std::string sParameter("k");

	for(int j=0;j!=vsSimpleReactions.size();j++)
	{
		//KinF(vsSimpleReactions[j],mSpecies);
		//std::cout << KinF(vsSimpleReactions[j],mSpecies) << std::endl;
		//vsR.push_back(KinF(vsSimpleReactions[j],mSpecies));
		//std::cout << vsR[j] << std::cout;
		vsR.push_back( sParameter + "[" + numberToString(j,true) + "]*" + KinF(vsSimpleReactions[j],mSpecies));
		mKinetics.emplace(vsSimpleReactions[j],vsR[j]);
	}

	//std::cout << vsR << std::endl;

	return vsR;
}



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
  boost::numeric::ublas::matrix<std::string> V;

  getReactionMatrix(vsSimpleReactions,mSpecies,cN);
  
  std::cout << "\n";
  std::cout << "\n";
  std::cout << cN;
  std::cout << "\n";
	
  std::map<std::string,std::string> mKinetics;
  std::map<std::string,std::string>::iterator iTKin;
  std::vector<std::string> vsR;
 
  vsR = KinPut(vsSimpleReactions,mSpecies,mKinetics);

  //V=V*vsR;

  //std::cout << V << "\n";

  //std::cout << cN*vsR << "\n";

  //for(iTKin=mKinetics.begin();iTKin != mKinetics.end();iTKin++)
  //{
    //std::cout << " Key " << iTKin->first << " Value " << iTKin->second << std::endl;
  //}
	
  std::map<std::string,std::string> mSpeciesKin;

  for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
  {
	  //std::cout << " Key " << iTmSpecies->first << " Value " << iTmSpecies->second << std::endl;
	  mSpeciesKin.emplace(iTmSpecies->first,"dx["+numberToString(iTmSpecies->second,true) +"]/dt = " + (cN*vsR)(iTmSpecies->second,0));
  }

  for(iTKin=mSpeciesKin.begin();iTKin != mSpeciesKin.end();iTKin++)
  {
    std::cout << " Key " << iTKin->first << " Value " << iTKin->second << std::endl;
  }
  
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
