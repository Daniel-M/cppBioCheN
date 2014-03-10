#include "incluidos.hpp"

void getReactantsVector(std::string sInput,std::map<std::string,int> mSpecies, std::vector< int >& viResult)
{
    std::vector<std::string> vsComplexBuffer;
    std::vector<std::string> vsLeftCompoundsBuffer;
    std::vector<std::string> vsRightCompoundsBuffer;
    std::vector<int> viReactants;
    std::vector<int> viProducts;
    
    viReactants.resize(viResult.size());
    viProducts.resize(viResult.size());
    
    int iStoichometricCoefficient=1;
    
	//getStringVector("->",sInput,vsComplexBuffer);
    
	boost::algorithm::erase_all(sInput,"-");
	boost::algorithm::split(vsComplexBuffer,sInput,boost::algorithm::is_any_of(">"));
    
	for(int i=0;i!=vsComplexBuffer.size();i++)
    {
      std::cout << vsComplexBuffer[i] << std::endl;
    }

	boost::algorithm::split(vsRightCompoundsBuffer,vsComplexBuffer[0],boost::algorithm::is_any_of("+"));
	boost::algorithm::split(vsLeftCompoundsBuffer,vsComplexBuffer[1],boost::algorithm::is_any_of("+"));
    
	//getStringVector("+",vsComplexBuffer[0],vsRightCompoundsBuffer);
	//getStringVector("+",vsComplexBuffer[1],vsLeftCompoundsBuffer);
    
    
    for(int i=0;i!=vsRightCompoundsBuffer.size();i++)
    {
        iStoichometricCoefficient = unStoichem(vsRightCompoundsBuffer[i]);
        viProducts[mSpecies.at(vsRightCompoundsBuffer[i])]=iStoichometricCoefficient;
    }
    
    for(int i=0;i!=vsLeftCompoundsBuffer.size();i++)
    {
        iStoichometricCoefficient = unStoichem(vsLeftCompoundsBuffer[i]);
        viReactants[mSpecies.at(vsLeftCompoundsBuffer[i])]=iStoichometricCoefficient;
    }

	

    for(int i=0;i!=viResult.size();i++)
    {
        viResult[i]=viProducts[i]-viReactants[i]; 
    }
	//std::cout << "\n";
   	
	//productory(mSpecies,viResult); 
    
	for(int i=0;i!=viResult.size();i++)
    {
       std::cout << " " << viResult[i]; 
    }
    std::cout << "\n";

}
