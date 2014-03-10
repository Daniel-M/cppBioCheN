//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <cmath>

//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>

#include "incluidos.hpp"

void productory(std::map<std::string,int> mSpecies, std::vector< int >& viResult)
{
	for(int j=0;j!=mSpecies.size();j++)
	{
		if(viResult[j] > 0)
		{
			if(viResult[j] == 1)
			{
				std::cout << "x[" + std::to_string(j) + "]";
			}
			else
			{
				std::cout << "pow(x[" + std::to_string(j) + "],"+ std::to_string(abs(viResult[j])) + ")";
			}
			//std::cout << std::endl;
		}
	}
}

void getMassActionLawKinetics(std::map<std::string,int> mSpecies/*, std::vector< int >& viResult*/)
{
    std::map<std::string,int>::iterator iTmSpecies;
	
	for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
    {
    	std::cout << " Key " << iTmSpecies->first << " Value " << iTmSpecies->second << std::endl;
    }	

	std::string sVComponent("");
	std::string sVarName("x");
}
