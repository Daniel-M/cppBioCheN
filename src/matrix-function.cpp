#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;


// Taken from http://www.cplusplus.com/articles/D9j2Nwbp/#eg
template <typename T>
std::string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

// template <typename T>
// T StringToNumber ( const string &Text )
// {
//     istringstream ss(Text);
//     T result;
//     return ss >> result ? result : 0;
// }

template <class T>
matrix<std::string> function(matrix<T> matrix1,matrix<std::string> matrix2)
// void function(matrix<T> matrix1,matrix<std::string> matrix2)
{
    std::cout << "Ja" << std::endl;
    
    if(matrix1.size2() == matrix2.size1())
    {
        matrix<std::string> result(matrix1.size1(),matrix2.size2());
        
        std::string sBuffer;
        
        for(int i=0;i != matrix1.size2();i++)
        {
            for(int j=0;j != matrix2.size1();j++)
            {
                for(int k=0;k != matrix1.size1(); k++)
                {
                    if( matrix1(i,k) != 0 )
                    {
//                         sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        if( NumberToString(matrix1(i,k)).substr(0,1) == "-")
                        {
                            sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        }
                        else if (sBuffer.size() < 1 )
                        {
                            sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        }
                        else
                        {
                            sBuffer += "+" + NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        }
                    }
                    

//                     std::cout << NumberToString(matrix1(i,k)) << std::endl;
                }
                
                result(i,j)=sBuffer;
                sBuffer="\0";
            }
        }
        
        std::cout << result << std::endl;
        
        return result;
    }
    else
    {
        return matrix2;
    }
    
    
//     return 0; 
}

template <class T>
matrix<std::string> function(matrix<std::string> matrix2,matrix<T> matrix1)
{

    std::cout << "Ja" << std::endl;
    
    if(matrix2.size2() == matrix1.size1())
    {
        matrix<std::string> result(matrix2.size1(),matrix1.size2());
        
        std::string sBuffer;
        
        for(int i=0;i != matrix2.size2();i++)
        {
            for(int j=0;j != matrix1.size1();j++)
            {
                for(int k=0;k != matrix2.size1(); k++)
                {
                    if( matrix1(k,j) != 0 )
                    {
//                         sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        if( NumberToString(matrix1(k,j)).substr(0,1) == "-")
                        {
                            sBuffer += NumberToString(matrix1(k,j)) + "*" + matrix2(i,k) ;
                        }
                        else if (sBuffer.size() < 1 )
                        {
                            sBuffer += NumberToString(matrix1(k,j)) + "*" + matrix2(i,k) ;
                        }
                        else
                        {
                            sBuffer += "+" + NumberToString(matrix1(k,j)) + "*" + matrix2(i,k) ;
                        }
                    }
                    

//                     std::cout << NumberToString(matrix1(i,k)) << std::endl;
                }
                
                result(i,j)=sBuffer;
                sBuffer="\0";
            }
        }
        
        std::cout << result << std::endl;
        
        return result;
    }
    else
    {
        return matrix2;
    }
  
}

int main () {
    
    matrix<double> m (3, 3);
    matrix<std::string> ms (3, 3);

    for (int i = 0; i < m.size1 (); ++ i)
    {
        for (int j = 0; j < m.size2 (); ++ j)
        {
            m (i, j) = i-j;
        }
    }
        
    ms(0,0)="a";
    ms(0,1)="b";
    ms(0,2)="c";
    ms(1,0)="d";
    ms(1,1)="e";
    ms(1,2)="f";
    ms(2,0)="g";
    ms(2,1)="h";
    ms(2,2)="i";
        
        
        
    std::cout << m << std::endl;
    std::cout << ms << std::endl;
    
    function(m,ms);

    function(ms,m);
}
