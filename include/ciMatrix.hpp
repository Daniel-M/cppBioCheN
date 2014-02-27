#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// #include "ciMatrix.hpp"

class ciMatrix
{
private:
    
    int _iRows;
    int _iColumns;
    
    std::vector< std::vector<int> > _vviMatrix;
    
public:
    
    ciMatrix();
    ciMatrix(int iRows,int iColumns);
    //     ciMatrix(int iFillValue,int iRows,int iColumns);
    
    //     ~ciMatrix();
    
    //     void fillWith(int iFillValue);
    void emplace(int i, int j, int iValue);
    void beIdentity();
    
    int rows();
    int columns();
    int numberOfElements();
    
    int at(int i, int j);
    
    ciMatrix identity();
    
    ciMatrix operator=(const ciMatrix& lhs);
    
    ciMatrix operator+(const ciMatrix& lhs);
    
    ciMatrix operator-(const ciMatrix& lhs);
    
    ciMatrix operator*(const ciMatrix& lhs);
    
    friend ciMatrix operator*(int mult, ciMatrix temp);
    
    friend std::ostream &operator<<( std::ostream &OutStream,const ciMatrix &matrix );
    
    
    
    
};

int ciMatrix::rows()
{
    return _iRows;
}


int ciMatrix::columns()
{
    return _iColumns;
}


int ciMatrix::numberOfElements()
{
    return _iRows*_iColumns;
}


void ciMatrix::emplace(int i, int j, int iValue)
{
    if( (i < _iRows) || (j < _iColumns))
    {
        _vviMatrix.at(j).at(i)=iValue;    
    }
    else
    {
        
    }
    
}

void ciMatrix::beIdentity()
{
    
    for(int j=0;j!=_iRows;j++)
    {
        for(int i=0;i!=_iColumns;i++)
        {
            if(i==j)
            {
                _vviMatrix.at(j).at(i) = 1;
            }
            else
            {
                _vviMatrix.at(j).at(i) = 0;
            }            
        }
    }

}


ciMatrix::ciMatrix()
{
    _iRows=2;
    _iColumns=2;
    
    for(int j=0;j!=_iRows;j++)
    {
        std::vector<int>* vVector = new std::vector<int>;
        
        for(int i=0;i!=_iColumns;i++)
        {
            vVector->push_back(0);
            //             std::cout << " " << vVector->at(i); 
        }
        //         std::cout << "\n";
        _vviMatrix.push_back(*vVector);
        
        delete(vVector);
    }
    
}


ciMatrix::ciMatrix(int iRows, int iColumns)
{
    _iRows = iRows;
    _iColumns = iColumns;
    
    //     for(int j=0;j!=iColumns;j++)
    for(int j=0;j!=_iRows;j++)
        //     for(int i=0;i!=iRows;i++)
    {
        std::vector<int>* vVector = new std::vector<int>;
        
        //         for(int i=0;i!=iRows;i++)
        for(int i=0;i!=_iColumns;i++)
            //         for(int j=0;j!=iColumns;j++)
        {
            vVector->push_back(0);
            //             std::cout << " " << vVector->at(i); 
        }
        //         std::cout << "\n";
        _vviMatrix.push_back(*vVector);
        
        delete(vVector);
    }
}

int ciMatrix::at(int i, int j)
{
    if( (i < _iRows) || (j < _iColumns))
    {
        return _vviMatrix.at(j).at(i);
    }
    else
    {
        
    }
}


ciMatrix ciMatrix::identity()
{
    ciMatrix result(this->_iRows,this->_iColumns);
    
    result.beIdentity();
    
    return (result);

}



ciMatrix ciMatrix::operator=(const ciMatrix& lhs)
{
    for(int i=0;i!=lhs._iColumns;i++)
    {
        
        for(int j=0;j!=lhs._iRows;j++)
        {
            _vviMatrix.at(i).at(j)= lhs._vviMatrix.at(i).at(j);
        }
    }
    
    return *this;
}


ciMatrix ciMatrix::operator+(const ciMatrix& lhs)
{
    //     ciMatrix temp(lhs._iRows,lhs._iColumns);
    ciMatrix temp = *this;
    
    if( (lhs._iRows == temp._iRows) || (lhs._iColumns == temp._iColumns))
    {
        for(int i=0;i!=lhs._iColumns;i++)
        {
            
            for(int j=0;j!=lhs._iRows;j++)
            {
                
                temp._vviMatrix.at(j).at(i)= temp._vviMatrix.at(j).at(i) + lhs._vviMatrix.at(j).at(i);
                
            }
        }
        
        return (temp);
    }
    else
    {
        return (lhs);
    }
}

ciMatrix ciMatrix::operator-(const ciMatrix& lhs)
{
    ciMatrix temp = *this;
    
    if( (lhs._iRows == temp._iRows) || (lhs._iColumns == temp._iColumns))
    {
        temp = temp + (-1*lhs);    
        return (temp);
    }
    else
    {
        return (lhs);
    }
}


ciMatrix ciMatrix::operator*(const ciMatrix& lhs)
{
    ciMatrix temp=*this;
    ciMatrix result(temp._iRows,lhs._iColumns);
    
    //     std::cout << " " << temp._iRows << "," << temp._iColumns << " - " << lhs._iRows << "," << lhs._iColumns << std::endl;
    
    if(temp._iColumns == lhs._iRows)
    {
        for(int i=0;i<temp._iRows;i++)
        {
            for(int j=0;j<lhs._iColumns;j++)
            {
                
                for(int k=0;k!=temp._iColumns;k++)
                {
                    //                     std::cout << " i,j,k " << i << "," << j << "," << k << std::endl;
                    //                     std::cout << " " << result._vviMatrix.at(j).at(i) << std::endl;
                    //                     std::cout << " " << lhs._vviMatrix.at(k).at(j) << std::endl;
                    //                     std::cout << " " << temp._vviMatrix.at(i).at(k) << std::endl;
                    result._vviMatrix.at(i).at(j) = result._vviMatrix.at(j).at(i) + temp._vviMatrix.at(i).at(k)*lhs._vviMatrix.at(k).at(j);
                    //                     std::cout << " " << result._vviMatrix.at(j).at(i) << std::endl;
                }
                
            }
        }
        
        
        //         std::cout << result._iRows << "," << result._iColumns << std::endl;
        
        return (result);
    }
    else
    {
        return (lhs);
    }
}

ciMatrix operator*(int mult, ciMatrix temp)
{  
    for(int i=0;i<temp._iRows;i++)
    {
        for(int j=0;j<temp._iColumns;j++)
        {
            temp._vviMatrix.at(i).at(j) = mult*temp._vviMatrix.at(i).at(j);
        }
    }
    return (temp);
}



std::ostream& operator<<(std::ostream& OutStream, const ciMatrix& matrix)
{
    //     for(int j=0;j<matrix._iColumns;j++)
    for(int j=0;j<matrix._iRows;j++)
    {
        OutStream << "|";
        
        //         for(int i=0;i<matrix._iRows;i++)
        for(int i=0;i<matrix._iColumns;i++)
        {
            //             OutStream << matrix._iRows << " -- " << matrix._iColumns << " i " << i << " j " << j << " = " << matrix._vviMatrix.at(j).at(i) << " ";
            //             OutStream << " " << matrix._vviMatrix.at(j).at(i) << " ";
            OutStream << " " << matrix._vviMatrix.at(j).at(i) << " ";
        }
        
        OutStream << "|\n";
    }
}

