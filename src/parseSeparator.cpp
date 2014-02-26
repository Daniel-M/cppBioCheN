#include <iostream>
#include <vector>
#include <fstream>
#include "incluidos.hpp"

/*! \brief Parse long strings like "A+B+C->D+E->G" into separated complexes (Feinberg definition)
 *  \param <sInput> Input string, this string will be split into sepparated "X->Y" reaction strings
 *  \return <vsOutput> By reference, this vector stores the resulting "X->Y" reaction strings properly ordered
 *
 *  When you run this function, it returns a vector of strings by reference
 */


// void parser(std::string sInput,std::vector<std::string>& vsOutput)
// {
//   
//   std::cout << sInput << std::endl;
//   
//   std::vector< std::string > vsPatterns;
//   
//   vsPatterns.push_back("<->");
//   vsPatterns.push_back("<=>");
//     
//   std::vector<std::string>* vsBuffer = new std::vector<std::string>;
//   
//  
//   int i=0;
//   
//   for(int i=0;i!=vsPatterns.size();i++)
//   {
//     
//     while(sInput.find(vsPatterns[i])<sInput.length())
//     {
//       
// 	/* The left side of sInput */
// 	std::string* sLTemp = new std::string(sInput.substr(0,sInput.find(vsPatterns[i])));
//       
// 	/* The rigth side of sInput */
// 	std::string* sRTemp = new std::string(sInput.substr(sInput.find(vsPatterns[i])+vsPatterns[i].length()));
//  
// 	/* Store the part of string into the vector */
// 	vsBuffer->push_back(*sLTemp);
// 	
// 	sInput=*sRTemp;
// 	
// 	if(sRTemp->find(vsPatterns[i])>sRTemp->length())
// 	{
// 	  vsBuffer->push_back(*sRTemp);
// 	}
// 	
// 	delete(sRTemp);
// 	delete(sLTemp);
//     }
//   }
//   
//   for(int i=0;i<vsBuffer->size()-1;i++)
//   {
//     vsOutput.push_back(vsBuffer->at(i)+"->"+vsBuffer->at(i+1));
//     vsOutput.push_back(vsBuffer->at(i+1)+"->"+vsBuffer->at(i));
//   }
// }


int main(void)
{
  std::fstream fsInput;
  fsInput.open("text.txt",std::fstream::in);
  
  std::fstream fsOutput;
  fsOutput.open("text-parsed.txt",std::ios::out | std::ios::trunc);
  
  std::vector<std::string> vsOutput;
  
  std::string sLine;
  
  if(fsInput.is_open() && fsOutput.is_open())
  {
  
  while(fsInput.eof()!=true)
  {
    std::getline(fsInput,sLine);
   
    if(sLine!="")
    {
//       std::cout << sLine << std::endl;
//       parser(sLine,vsOutput);
        orderReactionString(sLine,vsOutput);

    }
  }
  
  fsInput.close();
  
  
  for(int i=0;i<vsOutput.size();i++)
  {
    std::cout << " Tengo a " << i << " almacenando a " << vsOutput[i] << std::endl;
    fsOutput << vsOutput[i] << std::endl;

  }
  
  fsOutput.close();
  }
}
