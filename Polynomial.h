#include <iostream>
#include <vector>

using namespace std;

class Polynomial
{
private:
	std::vector<double> coefficients;						//vector of coefficients

public:
	Polynomial();											//constructor for zero coefficients
	Polynomial(double zero);								//constructor for one coefficient
	Polynomial(double zero, double one);					//constructor for two coefficients
	Polynomial(double zero, double one, double two);		//constructor for three coefficients
	Polynomial(vector<double> coefficientsVector);			//constructor for n coefficients, based on the size of the vector

	double GetOneCoefficient(int index);					// returns the coefficient on index 
	vector<double> GetAllCoefficients();					// returns whole vector 
	int GetDegree();										// returns degree of polynomial, for example polynomial 2x^2 + 3x^1 + 4 ==> 2
	double GetValueOfPolynomial(double x);					//calculates and returns the value of polynomial
	Polynomial Add(Polynomial O);							//sums two polynomials and returns result polynomial
	void PrintoutOfPolynomial();							//prints polynomial into console in humanly readable form
};

