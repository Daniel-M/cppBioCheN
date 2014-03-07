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
    //mNmatrix.resize(mSpecies.size(),vsSimpleReactions.size());
    
    //std::vector<int> viReactionVector;

    //std::cout << " Matrix size is " << mNmatrix.size1() << "," << mNmatrix.size2() << std::endl;

    //fillVector(viReactionVector,0,mSpecies.size());

    //for(int i=0;i<vsSimpleReactions.size();i++)
    //{
        
        //std::cout << " For reaction " << vsSimpleReactions[i] << std::endl;
        
        //getReactionVector(vsSimpleReactions[i],mSpecies,viReactionVector);
        
		//insertVectorToMatrix(mNmatrix,i,viReactionVector);
    //}
	
    
    mNmatrix.resize(mSpecies.size(),0);
    std::vector<int> viReactionVector;

	//std::cout << " Matrix size is " << mNmatrix.size1() << "," << mNmatrix.size2() << std::endl;

    viReactionVector.resize(mSpecies.size());

    for(int i=0;i<vsSimpleReactions.size();i++)
    {
        
        std::cout << " For reaction " << vsSimpleReactions[i] << std::endl;
        
        getReactionVector(vsSimpleReactions[i],mSpecies,viReactionVector);
		productory(mSpecies,viReactionVector);
		mNmatrix = mNmatrix + viReactionVector;
		//std::cout << mNmatrix << std::endl;
    }
}
