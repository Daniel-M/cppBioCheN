//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <cmath>

//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>

#include "incluidos.hpp"

void  getReactionMatrix(std::vector<std::string> vsSimpleReactions,std::map<std::string,int> mSpecies, boost::numeric::ublas::matrix<int>& mNmatrix)
{
   	std::cout << mSpecies.size() << "\n";

    mNmatrix.resize(mSpecies.size(),0);
    std::vector<int> viReactantsVector(mSpecies.size());
    std::vector<int> viProductsVector(mSpecies.size());
    std::vector<int> viReactionVector(mSpecies.size());

	//std::cout << " Vector size is " << viReactionVector.size() << std::endl;
	//std::cout << " Matrix size is " << mNmatrix.size1() << "," << mNmatrix.size2() << std::endl;

	//viReactionVector.resize(mSpecies.size());

    for(int i=0;i<vsSimpleReactions.size();i++)
    {
        
        std::cout << "For reaction " << vsSimpleReactions[i] << std::endl;
        
		getReactantsVector(vsSimpleReactions[i],mSpecies,viReactantsVector);
		getProductsVector(vsSimpleReactions[i],mSpecies,viProductsVector);

		viReactionVector = viProductsVector - viReactantsVector;

		std::cout << "Reaction\n";

		for(int j=0;j!=viReactionVector.size();j++)
		{
			std::cout << " " << viReactionVector[j];
		}

		std::cout << std::endl;

		mNmatrix = mNmatrix + viReactionVector;
		//std::cout << mNmatrix << std::endl;
    }
}
