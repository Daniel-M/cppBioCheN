#include <iostream>
#include <vector>

void fillVector(std::vector<int>& viInput,int iValue,int iQuantity)
{
  for(int i=0;i!=iQuantity;i++)
  {
    viInput.push_back(iValue);
  }
}

void fillVector(std::vector<double>& vdInput,double dValue,int iQuantity)
{
  for(int i=0;i!=iQuantity;i++)
  {
    vdInput.push_back(dValue);
  }
}
