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

template <class T>
class cubMatrix : public ublas::matrix<T>
{
  private:
  

  public:  
  
  cubMatrix<T>() {};
  cubMatrix<T>(int i, int j) : ublas::matrix<T>(i,j)
  {
	  
  }
  
  /*ublas::matrix<std::string>&*/ /*void operator*(const cubMatrix<T> &rhs)
  {
	  std::cout << "hello";
  }
  */
  
  cubMatrix<T> operator=(const cubMatrix<T>& lhs)
  {
	//(ublas::matrix<T>);
  }
  
  
  cubMatrix<std::string>& operator*(const ublas::matrix<std::string> &rhs)
  {
	  std::cout << " ublas ";
  }
  
  
  ublas::matrix<std::string>& operator*(const cubMatrix<T> &rhs)
  {
	  std::cout << "hello";
  }
  
  
  //operator * : ublas::matrix<T>.operator *;
};

//template <class T>
//cubMatrix<T>& cubMatrix<T>::operator*(const cubMatrix<T> &rhs)
//{

////   cubMatrix<T> temp;
  
////   std::cout << _cubMatrix << std::endl;  
  
////   _cubMatrix *= rhs._cubMatrix;
  
////   std::cout << "HI" << std::endl;  
  //std::cout << rhs._cubMatrix << std::endl;  
  
  //return *this;
  
//}

//template <class T>
//std::ostream& operator<<( /*std::ostream &OutStream,*/const cubMatrix<T> &matrix )
//{
  
//}


int main(void)
{
    cubMatrix<int> matriz_a(2,2);
    cubMatrix<int> matriz_b(2,2);
    cubMatrix<int> matriz_c(2,2);
    
    ublas::matrix<std::string> a(2,2);

    
     for (unsigned i = 0; i < 2; ++ i)
     {
         for (unsigned j = 0; j < 2; ++ j)
         {
             matriz_a (i, j) = 3 * i - 2*j;
         }
     }
     
     
     for (unsigned i = 0; i < 2; ++ i)
     {
         for (unsigned j = 0; j < 2; ++ j)
         {
             matriz_b (i, j) = - 3 * i + 2*j;
         }
     }

    
	a(0,0) = "a";
	a(1,0) = "b";
	a(0,1) = "c";
	a(1,1) = "d";

	//a=matriz_a*matriz_b;
    
    matriz_a*a;
    std::cout << matriz_a << std::endl;  
    
    std::cout << a << std::endl;  
    
    return(0);
  
}
