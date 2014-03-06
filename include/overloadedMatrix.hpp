#include <sstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

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
