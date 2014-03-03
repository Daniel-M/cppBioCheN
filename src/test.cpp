#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

#include "fillVector.hpp"
#include "incluidos.hpp"

#include <boost/numeric/ublas/vector.hpp>
// #include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
// #include <boost/numeric/ublas/triangular.hpp>
// #include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
namespace ublas = boost::numeric::ublas;


void insertVectorToMatrix(ublas::matrix<int>& mResult,int j,std::vector< int > viResult)
{
    for(int i=0;i!=viResult.size();i++)
    {
        mResult(i,j)=viResult[i];
    }
}

void function(std::string sInput/*std::vector< std::string > vsInput*/,std::map<std::string,int> mSpecies, std::vector< int >& viResult)
{
    /**
     * La intención es que la input se divida en dos partes, puesto que solo llega dividida por ->
     * luego, es preciso detectar las especies indicadas para construir el vector y'-y el cual será
     * entregado en viResult, pasandolo por referencia, la idea es construiruna matriz de reacciones
     * tal como lo recomienda al artículo de Pablo Villosada de PLoS
     * 
     */
    
    
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

//     for(int i=0;i!=vsComplexBuffer.size();i++)
//     {
//         getStringVector("+",vsComplexBuffer[i],vsCompoundsBuffer);
//     }
    getStringVector("+",vsComplexBuffer[0],vsRightCompoundsBuffer);
    
//     std::cout << "Right Add" << std::endl;
    
    getStringVector("+",vsComplexBuffer[1],vsLeftCompoundsBuffer);
    
//     std::cout << "Left Add" << std::endl;
    
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



void  getReactionMatrix(std::vector<std::string> vsSimpleReactions,std::map<std::string,int> mSpecies, ublas::matrix<int>& mNmatrix)
{//   std::vector< std::vector<int> > vviMatrix;

// ublas::matrix<int> cN(mSpecies.size(),vsSimpleReactions.size());
    
    mNmatrix.resize(mSpecies.size(),vsSimpleReactions.size());
    
    std::vector<int> viReactionVector;

    std::cout << " Matrix size is " << mNmatrix.size1() << "," << mNmatrix.size2() << std::endl;

    fillVector(viReactionVector,0,mSpecies.size());

    for(int i=0;i<vsSimpleReactions.size();i++)
    {
        
        std::cout << " For reaction " << vsSimpleReactions[i] << std::endl;
        
        function(vsSimpleReactions[i],mSpecies,viReactionVector);
        //     vviMatrix.push_back(viReactionVector);
        insertVectorToMatrix(mNmatrix,i,viReactionVector);
        //     function(vsSimpleReactions,mSpecies,viReactionVector);  
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
                //       parser(sLine,vsSimpleReactions);

                //orderReactionString(sLine,vsSimpleReactions);
                
            }
        }
        
        fsInput.close();
        
        
        for(int i=0;i<vsSimpleReactions.size();i++)
        {
//             std::cout << " Tengo a " << i << " almacenando a " << vsSimpleReactions[i] << std::endl;
            fsOutput << vsSimpleReactions[i] << std::endl;
            
        }
        
        fsOutput.seekg(fsOutput.beg);
        
        while(fsOutput.eof()!=true)
        {
            std::getline(fsOutput,sLine);
            
//             std::cout << sLine << std::endl;
            
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
  
//   std::vector<int> viReactionVector;
//   std::vector< std::vector<int> > vviMatrix;
  
//   ublas::matrix<int> cN(mSpecies.size(),vsSimpleReactions.size());
    ublas::matrix<int> cN;
    
    getReactionMatrix(vsSimpleReactions,mSpecies,cN);
  
//   std::cout << " Matrix size is " << cN.size1() << "," << cN.size2() << std::endl;
//   
//   fillVector(viReactionVector,0,mSpecies.size());
//   
//   for(int i=0;i<vsSimpleReactions.size();i++)
//   {
//     
//     std::cout << " For reaction " << vsSimpleReactions[i] << std::endl;
//        
//     function(vsSimpleReactions[i],mSpecies,viReactionVector);
// //     vviMatrix.push_back(viReactionVector);
//     insertVectorToMatrix(cN,i,viReactionVector);
// //     function(vsSimpleReactions,mSpecies,viReactionVector);  
//   }
  
//     for(int j=0;j!=vviMatrix.size()-1;j++)
//     {
//         for(int i=0;i!=vviMatrix.at(j).size();i++)
//         {
//             std::cout << vviMatrix.at(j).at(i) /*<< std::endl*/;
//             cN(i,j) = vviMatrix.at(j).at(i);
//         }
//         std::cout << "\n";
//     }
//   
  
  std::cout << "\n";
  std::cout << "\n";
  std::cout << cN;
  std::cout << "\n";
  
//   for(iTmSpecies=mSpecies.begin();iTmSpecies != mSpecies.end();iTmSpecies++)
//   {
// //       viCompounds[iTmSpecies->second-1]=mSpecies
//   }
//   
//   fsOutput.close();
//   
//   for(int j=0;j!=vviMatrix.size();j++)
//   {
// //       std::cout << " j " << j << std::endl;
//       
//       for(int i=0;i!=vviMatrix.at(j).size();i++)
//       {
//           std::cout << vviMatrix.at(j).at(i) << " ";
//       }
//       std::cout << "\n";
//   }
// //   
//   for(int j=0;j!=vviMatrix.size()-1;j++)
//   {
//       for(int i=0;i!=vviMatrix.at(j).size();i++)
//       {
//           fillVector(viReactionVector,0,mSpecies.size());
// //           viReactionVector.at(i)=vviMatrix.at(j+1).at(i)-vviMatrix.at(j).at(i);
//           std::cout << vviMatrix.at(j+1).at(i) << " - "<< vviMatrix.at(j).at(i)  << " = " << vviMatrix.at(j+1).at(i) - vviMatrix.at(j).at(i) << std::endl;
//       }
//       vviNMatrix.push_back(viReactionVector);
//       std::cout << "\n";
//   }
//   
//   
//   for(int j=0;j!=vviNMatrix.size();j++)
//   {
//       //       std::cout << " j " << j << std::endl;
//       
//       for(int i=0;i!=vviNMatrix.at(j).size();i++)
//       {
//           std::cout << vviNMatrix.at(j).at(i) << " ";
//       }
//       std::cout << "\n";
//   }
//   
  
  
  return 0;
  
}
