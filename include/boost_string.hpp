#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/find_iterator.hpp>
#include <boost/algorithm/string/iter_find.hpp>
#include <boost/algorithm/string/classification.hpp> 

void getSimpleReactions(std::string sInput,std::vector<std::string>& vsSimpleReactions)
{
	std::vector<std::string> vsBuffer;
	std::vector<std::string> vsReactForward;
	std::vector<std::string> vsReactBackward;

	/* This part should be removed, the string addecuation must be at reading time */
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

	for(int j=0;j != vsBuffer.size()-1;j++)
	{
		vsReactForward.push_back(vsBuffer[j]+"->"+vsBuffer[j+1] );
	}
	
	std::cout << "Changing to backwards\n";

	for(int i=0;i < vsBuffer.size();i++)
	{
		if( vsBuffer[i].find("<") < vsBuffer[i].length())
		{
			std::cout << i << " - " << vsBuffer[i] << std::endl;
			vsReactBackward.push_back(vsBuffer[i+1]+"->"+vsBuffer[i]);

		}
	}
	
	for(int j=0;j != vsReactForward.size();j++)
	{
		boost::algorithm::erase_all(vsReactForward[j],"<");
	}

	for(int i=vsReactForward.size();i!=0;i--)
	{
		vsSimpleReactions.push_back(vsReactForward[i]);
	}
	
	for(int j=0;j != vsReactBackward.size();j++)
	{
		boost::algorithm::erase_all(vsReactBackward[j],"<");
	}

	for(int i=vsReactBackward.size();i!=0;i--)
	{
		vsSimpleReactions.push_back(vsReactBackward[i]);
	}
}
