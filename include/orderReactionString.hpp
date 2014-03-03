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

	std::cout << sInput << std::endl;

	std::vector< std::string > vsPatterns;

	vsPatterns.push_back("->");
	vsPatterns.push_back("<->");
	vsPatterns.push_back("<=>");
	
	std::vector<std::string>* vsBuffer = new std::vector<std::string>;


	for(int i=0;i!=vsPatterns.size();i++)
	{
			
	}
}
