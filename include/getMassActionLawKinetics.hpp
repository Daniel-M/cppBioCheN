//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <cmath>

//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>

#include "incluidos.hpp"

template <class T>
std::vector<T> getColumnMatrix(T tNum,boost::numeric::ublas::matrix< T >& ublastMatrix)
{
	std::vector<T> vtBuffer;

	for(int j=0;j!=ublastMatrix.size1();j++)
	{
		vtBuffer.push_back(ublastMatrix(j,tNum));
	}

	//std::cout << vtBuffer << "\n";

	return vtBuffer;
}


std::string getKineticReactionComponent(std::map<std::string,int> mSpecies, std::vector< int >& viReactionVector)
{
	std::map<std::string,int>::iterator iTmSpecies;
	std::string sKineticReactionComponent("");

	std::string sVarName("x");
	std::string sPotentiation("pow");


	for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
	{
		if( viReactionVector[iTmSpecies->second] > 1)
		{

			std::cout << "\nHi 1 " << viReactionVector[iTmSpecies->second] << "\n";

			sKineticReactionComponent += sPotentiation +"(" + sVarName + "[" + numberToString(iTmSpecies->second).substr(0,numberToString(iTmSpecies->second).size()-1)+ "]," + numberToString(viReactionVector[iTmSpecies->second]).substr(0,numberToString(viReactionVector[iTmSpecies->second]).size()-1) + ")";
			//sKineticReactionComponenti += "*";

			if(iTmSpecies != mSpecies.end())
			{
				sKineticReactionComponent += "*";
			}
		}
		else if (viReactionVector[iTmSpecies->second] == 1)
		{
			std::cout << "\nHi 2 " << viReactionVector[iTmSpecies->second]  << " -- " << sVarName + "[" + numberToString(iTmSpecies->second).substr(0,numberToString(iTmSpecies->second).size()-1)+ "]" << "\n";
			sKineticReactionComponent += sVarName + "[" + numberToString(iTmSpecies->second).substr(0,numberToString(iTmSpecies->second).size()-1) + "]";
			//sKineticReactionComponenti += "*";
			
			if(iTmSpecies != mSpecies.end())
			{
				sKineticReactionComponent += "*";
			}
		}

	
	}

	return sKineticReactionComponent;
}


void getMassActionLawKinetics(std::map<std::string,int> mSpecies, std::vector< int >& viReactionVector)
{
    std::map<std::string,int>::iterator iTmSpecies;
	
	std::cout << getKineticReactionComponent(mSpecies, viReactionVector);
}


void getMassActionLawKinetics(std::map<std::string,int> mSpecies, boost::numeric::ublas::matrix< int >& Matrix)
{
    std::map<std::string,int>::iterator iTmSpecies;
	std::vector<int> viReactionBuffer;

	for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
    {
    	std::cout << " Key " << iTmSpecies->first << " Value " << iTmSpecies->second << std::endl;
    }
	
	for(int j=0;j!=Matrix.size2();j++)
	{
		viReactionBuffer = getColumnMatrix(j,Matrix);
		getMassActionLawKinetics(mSpecies,viReactionBuffer);
	}
}
