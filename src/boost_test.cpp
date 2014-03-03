#include <iostream>
#include <boost/program_options/options_description.hpp>
//#include 
#include "boost_string.hpp"

namespace po = boost::program_options;

using namespace std;

int main(void)
{
	std::string sInput("A +b+l-> j+l<=>p<->3e");
	std::vector<std::string> vsBuffer;
	std::vector<std::string> vsReactForward;
	std::vector<std::string> vsReactBackward;

	boost::algorithm::erase_all(sInput," ");
	std::cout << sInput << std::endl;
	boost::algorithm::to_upper(sInput);
	std::cout << sInput << std::endl;
	boost::algorithm::erase_all(sInput,"-");
	boost::algorithm::erase_all(sInput,"=");
	std::cout << sInput << std::endl;

	//boost::algorithm::find_all(vsBuffer,sInput,"->");
	boost::algorithm::split(vsBuffer,sInput,boost::algorithm::is_any_of(">"));

	for(int i=0;i < vsBuffer.size();i++)
	{
		std::cout << vsBuffer[i] << std::endl;
	}
	
	vsReactForward = vsBuffer;

	//std::cout << "sin corregir \n";
	
	//for(int j=0;j != vsReactForward.size();j++)
	//{
		//std::cout << vsReactForward[j] << std::endl;
	//}
	
	//for(int j=0;j != vsReactForward.size();j++)
	//{
		//boost::algorithm::erase_all(vsReactForward[j],"<");
	//}

	//std::cout << "corregidas \n";

	for(int j=0;j != vsBuffer.size()-1;j++)
	{
		//std::cout << vsReactForward[j] << std::endl;
		
		vsReactForward.push_back(vsBuffer[j]+"->"+vsBuffer[j+1] );
		
	}
	
	std::cout << "Changing to backwards\n";

	for(int i=0;i < vsBuffer.size();i++)
	{
		if( vsBuffer[i].find("<") < vsBuffer[i].length())
		{
			std::cout << i << " - " << vsBuffer[i] << std::endl;
			//boost::algorithm::erase_all(vsBuffer[i+1],"<");
			//boost::algorithm::erase_all(vsBuffer[i],"<");

			vsReactBackward.push_back(vsBuffer[i+1]+"->"+vsBuffer[i]);

		}
	}
	
	for(int j=0;j != vsReactForward.size();j++)
	{
		boost::algorithm::erase_all(vsReactForward[j],"<");
	}

	for(int i=0;i < vsReactForward.size();i++)
	{
		std::cout << vsReactForward[i] << std::endl;
	}
	
	for(int j=0;j != vsReactBackward.size();j++)
	{
		boost::algorithm::erase_all(vsReactBackward[j],"<");
	}

	for(int i=0;i < vsReactBackward.size();i++)
	{
		std::cout << vsReactBackward[i] << std::endl;
	}
}
