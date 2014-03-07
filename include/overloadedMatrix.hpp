#include <sstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


/**\brief This function converts a number data type like \a int, \a float, or\a double to \a std::string.
 *        The result it's used on symbolic multiplications of boost::numeric::ublas::matrix.
 *
 * This function converts a number data type to a \a std::string, so the result it's used on symbolic
 * multiplications of boost::numeric::ublas::matrix. When the number is +1 it just returns "", when
 * the number is -1, the function returns "-".
 *
 * \tparam[in] number Number data type to be converted to \a std::string.
 * \return \a std::string of the number given. If the number
 */
template <typename T>
std::string NumberToString (const T& number)
{
    std::ostringstream ss;
    ss << number;
	if (ss.str() == "1")
	{
		return "";
	}
	else if (ss.str() == "-1")
	{
		return "-";
	}
	else
	{
	    return ss.str()+ "*";
	}
}

/**\brief This function overloads the boost::numeric::ublas::matrix::operator* to allow products between different matrix types
 *
 * This function overloads the boost::numeric::ublas::matrix::operator* in order to allow matrix products between
 * different data types, but it returns boost::numeric::ublas::matrix<\a std::string >.
 * The function iterates the product just as defined by standard matrix multiplication, for a matrix
 * \f[ c_{i,j} = \sum_{k=1}a_{i,k}b_{k,j}\f]
 *
 * \relates NumberToString
 *
 * \tparam[in] matrix1 Matrix of atemplate type. \a int,\a float, or\a double expected.i
 * \param[in] matrix2 A \a std::string matrix
 * \return A matrix made up of \a std::string, as the result of the multiplication of matrix1 and matrix2
 */
template <class T>
boost::numeric::ublas::matrix<std::string> operator*(const boost::numeric::ublas::matrix<T>& matrix1, const boost::numeric::ublas::matrix<std::string>& matrix2)
{
    if (matrix1.size2() == matrix2.size1())
    {
        boost::numeric::ublas::matrix<std::string> result(matrix1.size1(), matrix2.size2());

        std::string sBuffer;

        for (int i=0; i != matrix1.size2(); i++)
        {
            for (int j=0; j != matrix2.size1(); j++)
            {
                for (int k=0; k != matrix1.size1(); k++)
                {
                    if (matrix1(i, k) != 0)
                    {
                        if (NumberToString(matrix1(i, k)).substr(0, 1) == "-")
							//sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
							sBuffer += NumberToString(matrix1(i,k)) + matrix2(k,j) ;
                        else if (sBuffer.size() < 1)
							//sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
							sBuffer += NumberToString(matrix1(i,k)) + matrix2(k,j) ;
                        else
							//sBuffer += "+" + NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
							sBuffer += "+" + NumberToString(matrix1(i,k)) + matrix2(k,j) ;
                    }
                }
                result(i, j) = sBuffer;
                sBuffer = "";
            }
        }
        return result;
    }
    else
	{
        return matrix2;
	}
}

/**
 * \overload  boost::numeric::ublas::matrix<std::string> operator* when changing the order of multiplication.
 */
template <class T>
boost::numeric::ublas::matrix<std::string> operator*(const boost::numeric::ublas::matrix<std::string>& matrix1, const boost::numeric::ublas::matrix<T>& matrix2)//
{
    if (matrix1.size2() == matrix2.size1())
    {
        boost::numeric::ublas::matrix<std::string> result(matrix1.size1(), matrix2.size2());

        std::string sBuffer;

        for (int i=0; i != matrix1.size1(); i++)
        {
            for (int j=0; j != matrix2.size2(); j++)
            {
                for (int k=0; k != matrix1.size2(); k++)
                {
                    if (matrix2(k, j) != 0)
                    {
						//if (NumberToString(matrix2(i, k)).substr(0, 1) == "-")
						if (std::to_string(matrix2(i,k)).substr(0,1) == "-")
							sBuffer += NumberToString(matrix2(k,j)) + matrix1(i,k) ;
							//sBuffer += NumberToString(matrix2(k,j)) + "*" + matrix1(i,k) ;
                        else if (sBuffer.size() < 1)
							sBuffer += NumberToString(matrix2(k,j)) + matrix1(i,k) ;
							//sBuffer += NumberToString(matrix2(k,j)) + "*" + matrix1(i,k) ;
                        else
							sBuffer += "+" + NumberToString(matrix2(k,j)) + matrix1(i,k) ;
							//sBuffer += "+" + NumberToString(matrix2(k,j)) + "*" + matrix1(i,k) ;
                    }
                }
                result(i, j) = sBuffer;
				//sBuffer = "";
                sBuffer.clear();
            }
        }
        return result;
    }
    else
	{
        return matrix2;
	}
}

/**\brief This function overloads the boost::numeric::ublas::matrix::operator+ to append \a std::vectors to libboost matrices
 *
 * This function overloads the boost::numeric::ublas::matrix::operator+ to provide a method of append vectors 
 * to matrices as columns. The input matrix is copied, the copy is resized by one column and the given vector
 * is appended.
 * \f[ c_{m \times n} + \vec{v} = c_{m\times  \left(n+1\right)}\f]
 *
 * \tparam[in] Matrix Matrix of a template type. \a int,\a float, or\a double expected.
 * \param[in] vtVector \a std::vector to be appended to Matrix.
 * \return A matrix resized by one column by the vector vtVector.
 * \note \a vtVector.size() is compared to \a Matrix.size1() in order to allow appending. Matrix rows and vector elements
 *       must be equal.
 */
template <class T>
boost::numeric::ublas::matrix<T> operator + (const boost::numeric::ublas::matrix<T>& Matrix,const std::vector<T>& vtVector)
{
	/* Add vectors as new columns at the end of the matrix*/

	boost::numeric::ublas::matrix<T> resultMatrix(Matrix);

	
	if(vtVector.size() == resultMatrix.size1())
	{
		resultMatrix.resize(Matrix.size1(),Matrix.size2()+1,true);

		for(int i=0;i!=vtVector.size();i++)
    	{
			resultMatrix(i,resultMatrix.size2()-1)=vtVector[i];
    	}
	}

	return resultMatrix;
}
