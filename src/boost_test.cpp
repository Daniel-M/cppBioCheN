#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include "fillVector.hpp"
#include "incluidos.hpp"
#include "getSimpleReactions.hpp"

using namespace std;


void insertVectorToMatrix(boost::numeric::ublas::matrix<int>& mResult,int j,std::vector< int > viResult)
{
    for(int i=0;i!=viResult.size();i++)
    {
        mResult(i,j)=viResult[i];
    }
}

void getReactionVector(std::string sInput,std::map<std::string,int> mSpecies, std::vector< int >& viResult)
{
    /**
     * La intención es que la input se divida en dos partes, puesto que solo llega dividida por ->
     * luego, es preciso detectar las especies indicadas para construir el vector y'-y el cual será
     * entregado en viResult, pasandolo por referencia, la idea es construir una matriz de reacciones
     * tal como lo recomienda al artículo de Pablo Villosada de PLoS
     **/
    
    
    std::vector<std::string> vsComplexBuffer;
    std::vector<std::string> vsLeftCompoundsBuffer;
    std::vector<std::string> vsRightCompoundsBuffer;
    std::vector<int> viReactants;
    std::vector<int> viProducts;
    
    viReactants.resize(viResult.size());
    viProducts.resize(viResult.size());
    
    int iStoichometricCoefficient=1;
    
    getStringVector("->",sInput,vsComplexBuffer);
    
    for(int i=0;i!=vsComplexBuffer.size();i++)
    {
      std::cout << vsComplexBuffer[i] << std::endl;
    }

    getStringVector("+",vsComplexBuffer[0],vsRightCompoundsBuffer);
    getStringVector("+",vsComplexBuffer[1],vsLeftCompoundsBuffer);
    
    
    for(int i=0;i!=vsRightCompoundsBuffer.size();i++)
    {
        iStoichometricCoefficient = unStoichem(vsRightCompoundsBuffer[i]);
        viProducts[mSpecies.at(vsRightCompoundsBuffer[i])-1]=iStoichometricCoefficient;
    }
    
    for(int i=0;i!=vsLeftCompoundsBuffer.size();i++)
    {
        iStoichometricCoefficient = unStoichem(vsLeftCompoundsBuffer[i]);
        viReactants[mSpecies.at(vsLeftCompoundsBuffer[i])-1]=iStoichometricCoefficient;
    }
    
    for(int i=0;i!=viResult.size();i++)
    {
        viResult[i]=viProducts[i]-viReactants[i]; 
    }
    std::cout << "\n";
    
    for(int i=0;i!=viResult.size();i++)
    {
        std::cout << " " << viResult[i]; 
    }
    std::cout << "\n";

}



void  getReactionMatrix(std::vector<std::string> vsSimpleReactions,std::map<std::string,int> mSpecies, boost::numeric::ublas::matrix<int>& mNmatrix)
{
    mNmatrix.resize(mSpecies.size(),vsSimpleReactions.size());
    
    std::vector<int> viReactionVector;

    std::cout << " Matrix size is " << mNmatrix.size1() << "," << mNmatrix.size2() << std::endl;

    fillVector(viReactionVector,0,mSpecies.size());

    for(int i=0;i<vsSimpleReactions.size();i++)
    {
        
        std::cout << " For reaction " << vsSimpleReactions[i] << std::endl;
        
        getReactionVector(vsSimpleReactions[i],mSpecies,viReactionVector);
        
		insertVectorToMatrix(mNmatrix,i,viReactionVector);
    }
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
                std::cout << sLine << std::endl;
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
                getSpeciesMap("->",sLine,mSpecies);
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
