#include <iostream>
#include <vector>
#include <fstream>
#include "incluidos.hpp"

/*! @brief Parse long strings like "A+B+C<->D+E->G" into separated complexes (Feinberg definition)
 *  @param <sInput> Input string, this string will be split into sepparated "X->Y" reaction strings
 *  @return <vsOutput> By reference, this vector stores the resulting "X->Y" reaction strings properly ordered
 *
 *  When you run this function, it returns a vector of strings by reference, parse long strings like "A+B+C->D+E->G"
 *  into separated complexes (Feinberg definition) "A+B+C->D+E, "D+E->A+B+C" and so on.
 */


void orderReactionString(std::string sInput,std::vector<std::string>& vsOutput)
{
  
	//std::cout << sInput << std::endl;
  
  std::vector< std::string > vsPatterns;
  
  vsPatterns.push_back("<->");
  vsPatterns.push_back("<=>");
  vsPatterns.push_back("->");

  std::vector<std::string>* vsBuffer = new std::vector<std::string>;

  //std::cout << "subs " <<  sInput.substr(sInput.find(vsPatterns[2])-vsPatterns[2].length()+1,1) << std::endl;
  //std::vector<std::string>::iterator vit=vsOutput.end();
 
  for(int i=0;i!=vsPatterns.size();i++)
  {
 
	std::cout << vsPatterns[i] << std::endl;

	if(vsPatterns[i] == "->" && sInput.substr(sInput.find("->"),1) != "<" ) 
		//sInput.substr(sInput.find(vsPatterns[i])-vsPatterns[i].length()+1,1) != "<" ) 
	{
			
		std::cout << sInput << std::endl;
		
		/* The left side of sInput */
		std::string* sLTemp = new std::string(sInput.substr(0,sInput.find(vsPatterns[i])));
			  
		/* The rigth side of sInput */
		std::string* sRTemp = new std::string(sInput.substr(sInput.find(vsPatterns[i])+vsPatterns[i].length()));
		
		vsOutput.push_back(*sLTemp+"->"+*sRTemp);

		//std::cout << vit << std::endl;
		std::cout << "by now " << vsOutput.back() << std::endl;
		
		delete(sRTemp);
		delete(sLTemp);

	}
	else
	{
		std::cout << sInput << std::endl;
		
		while(sInput.find(vsPatterns[i]) < sInput.length())
		{
		  
			/* The left side of sInput */
			std::string* sLTemp = new std::string(sInput.substr(0,sInput.find(vsPatterns[i])));
			  
			/* The rigth side of sInput */
			std::string* sRTemp = new std::string(sInput.substr(sInput.find(vsPatterns[i])+vsPatterns[i].length()));
		 
			/* Store the part of string into the vector */
			vsBuffer->push_back(*sLTemp);
			
			sInput=*sRTemp;
			
			std::cout << " ... " << sInput << std::endl;
			
			if(sRTemp->find(vsPatterns[i])>sRTemp->length())
			{
			  vsBuffer->push_back(*sRTemp);
			}
			
			delete(sRTemp);
			delete(sLTemp);
		}

		std::cout << " debug " << std::endl;

		for(int i=0;i<vsBuffer->size();i++)
		{
			std::cout << "aa " << i << " - " << vsBuffer->at(i) << std::endl;
		}

		for(int j=0;j<vsBuffer->size()-1;j++)
		{
			vsOutput.push_back(vsBuffer->at(j)+"->"+vsBuffer->at(j+1));
			vsOutput.push_back(vsBuffer->at(j+1)+"->"+vsBuffer->at(j));
		}
	}
  }
  
  
}
