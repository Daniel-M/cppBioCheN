// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <string>
// // #include <boost/numeric/ublas/matrix.hpp>
// // #include <boost/numeric/ublas/io.hpp>
// 
// // #include "ciMatrix.hpp"
// 
// #ifndef INVERT_MATRIX_HPP
// #define INVERT_MATRIX_HPP
// REMEMBER to update "lu.hpp" header includes from boost-CVS
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
namespace ublas = boost::numeric::ublas;
/* Matrix inversion routine.
 Uses lu_factorize and l*u_substitute in uBLAS to invert a matrix */
template<class T>
bool InvertMatrix (const ublas::matrix<T>& input, ublas::matrix<T>& inverse) {
    using namespace boost::numeric::ublas;
    typedef permutation_matrix<std::size_t> pmatrix;
    // create a working copy of the input
    matrix<T> A(input);
    // create a permutation matrix for the LU-factorization
    pmatrix pm(A.size1());
    // perform LU-factorization
    int res = lu_factorize(A,pm);
    if( res != 0 ) return false;
    // create identity matrix of "inverse"
    inverse.assign(ublas::identity_matrix<T>(A.size1()));
    // backsubstitute to get the inverse
    lu_substitute(A, pm, inverse);
    return true;
}
// #endif //INVERT_MATRIX_HPP


int main(void)
{
//     ciMatrix m(2,2);
//     ciMatrix a(2,3);
//     std::cout << "\n";
//     ciMatrix b(3,2);
//     
//     
//     a.emplace(0,0,1);
//     b.emplace(0,1,1);
//     b.emplace(0,0,1);
//     
//     std::cout << a;
//     
//     std::cout << "\n\n";
//     
//     std::cout << b;
//     
//     std::cout << "\n";
//     
//     std::cout << a*b;
//     std::cout << "\n";
//     
//     std::cout << b*a;
//     std::cout << "\n";
//     
//     std::cout << 3*b*a;
//     std::cout << "\n";
//     
//     ciMatrix m=(b*a);
//     
// //     m.beIdentity();
//     
//     std::cout << m.identity();
//     std::cout << "\n";
//     std::cout << 3*m-m;
//     std::cout << "\n";
   
    using namespace boost::numeric::ublas;
    matrix<double> m (3, 3);
    matrix<double> mi(3, 3),r(3,3);
    
    for (unsigned i = 0; i < m.size1 (); ++ i)
    {
        for (unsigned j = 0; j < m.size2 (); ++ j)
        {
            m (i, j) = 3 * i - 2*j;
        }
    }
    
    std::cout << m << std::endl;
    
    if (InvertMatrix(m,mi) == true)
    {   
        std::cout << mi << std::endl;
    }
    
    r= -m;
    
    std::cout << r << std::endl;
    
    return 0;
}
