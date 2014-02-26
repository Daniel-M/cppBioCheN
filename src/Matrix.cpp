

#include <boost/numeric/ublas/matrix.hpp>

template <typename T>
std::string NumberToString (const T& number)
{
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

template <class T>
class Matrix: public boost::numeric::ublas::matrix<T>
{
public:
    Matrix(const Matrix<T>& matrix): boost::numeric::ublas::matrix<T>(matrix) { }
    Matrix(int i, int j): boost::numeric::ublas::matrix<T>(i,j)  { }

	//std::ostream& operator<<(const Matrix<T>& matrix) : boost::numeric::ublas::matrix<T>::operator<<(matrix)
	//{
		
	//}
};

template <class T>
Matrix<std::string> operator*(const Matrix<T>& matrix1, const Matrix<std::string>& matrix2)
{
    if (matrix1.size2() == matrix2.size1())
    {
        Matrix<std::string> result(matrix1.size1(), matrix2.size2());

        std::string sBuffer;

        for (int i=0; i != matrix1.size2(); i++)
        {
            for (int j=0; j != matrix2.size1(); j++)
            {
                for (int k=0; k != matrix1.size1(); k++)
                {
                    if (matrix1(i, k) != 0)
                    {
//                         sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        if (NumberToString(matrix1(i, k)).substr(0, 1) == "-")
                            sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        else if (sBuffer.size() < 1)
                            sBuffer += NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                        else
                            sBuffer += "+" + NumberToString(matrix1(i,k)) + "*" + matrix2(k,j) ;
                    }

//                     std::cout << NumberToString(matrix1(i,k)) << std::endl;
                }

                result(i, j) = sBuffer;
                sBuffer = "";
            }
        }

        // std::cout << result << std::endl;

        return result;
    }
    else
        return matrix2;
}

template <class T>
Matrix<std::string> operator*(const Matrix<std::string>& matrix1, const Matrix<T>& matrix2)
{
    return matrix2*matrix1;
}

int main()
{
    Matrix<double> m (3, 3);
    Matrix<std::string> ms (3, 3);

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
	
	//std::cout << m << std::endl;
	//std::cout << ms << std::endl;

    Matrix<std::string> mr1(m*ms);
    Matrix<std::string> mr2(ms*m);

    for (int i = 0; i < m.size1 (); ++ i)
    {
        for (int j = 0; j < m.size2 (); ++ j)
        {
            std::cout << mr1 (i, j) << std::endl;
        }
    }


	//std::cout << mr1 << std::endl;
//    std::cout << ms << std::endl;

//    function(m,ms);
//
//    function(ms,m);
}


