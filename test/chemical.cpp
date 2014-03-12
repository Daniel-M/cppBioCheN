#include <cmath>
#include <iostream>
#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>

using namespace std;
using namespace boost::numeric::odeint;

const vector<double> k(6,1.0);

typedef boost::array< double , 5 > state_type;

void ode_system( const state_type &x , state_type &dxdt , double t )
{
	
	dxdt[1] = -k[0]*x[1]+k[1]*pow(x[0],2)-k[2]*x[1]*x[3]+k[3]*x[2]+k[5]*x[0]*x[4];
	dxdt[0] = 2*k[0]*x[1]-2*k[1]*pow(x[0],2)+k[4]*x[2]-k[5]*x[0]*x[4];
	dxdt[3] = -k[2]*x[1]*x[3]+k[3]*x[2]+k[5]*x[0]*x[4];
	dxdt[2] = k[2]*x[1]*x[3]-k[3]*x[2]-k[4]*x[2];
	dxdt[4] = k[4]*x[2]-k[5]*x[0]*x[4];
	
}

void write_ode( const state_type &x , const double t )
{
	cout << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << '\t' << x[3] << '\t' << x[4] << endl;
}

int main(int argc, char **argv)
{
	state_type x = { 8.0 , 5.0 , 3.5, 2.1, 4.4}; // initial conditions
	integrate( ode_system , x , 0.0 , 0.6 , 0.01 , write_ode );
}
