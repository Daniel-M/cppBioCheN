#include <iostream>
#include <vector>

#include <boost/numeric/ublas/matrix.hpp>


using namespace std;


void insertVectorToMatrix(boost::numeric::ublas::matrix<int>& mResult,int j,std::vector< int > viResult)
{
    for(int i=0;i!=viResult.size();i++)
    {
        mResult(i,j)=viResult[i];
    }
}
