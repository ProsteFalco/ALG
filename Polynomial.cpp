#include "Polynomial.h"


//All of the constructors are pretty self-explanatory, just inputing coefficients in few ways
Polynomial::Polynomial() {
	this->coefficients = {};
}

Polynomial::Polynomial(double zero) {
	this->coefficients = {zero};
}

Polynomial::Polynomial(double zero, double one) {
	this->coefficients = { zero , one };
}

Polynomial::Polynomial(double zero, double one, double two) {
	this->coefficients = { zero , one , two };
}

Polynomial::Polynomial(vector<double> coefficientsVector) {
	this->coefficients = coefficientsVector;
}

//returns the coefficient on index, for example in polynomial 3x^2 + 6x^1 + 2 with index 2 returns 3
double Polynomial::GetOneCoefficient(int index) {
	if(index <= coefficients.size())
		return this->coefficients[index];
	else 
		return 0;
}

vector<double> Polynomial::GetAllCoefficients() {
	return this->coefficients;
}

int Polynomial::GetDegree() {
	return coefficients.size() - 1; //size of vector {3, 4, 5} is polynomial degree [2] since 5 * x^0 and 3 * x^[2]
}

double Polynomial::GetValueOfPolynomial(double x) {

	double result = 0;
	int iterrations = 0;

	for (double c : coefficients) { //"foreach" that sums values of coefficient * x to the power of degree
		result += c * pow(x, iterrations);
		iterrations++;
	}
	
	return result; 
}

Polynomial Polynomial::Add(Polynomial O) {
	
	std::vector<double> other = O.GetAllCoefficients();
	std::vector<double> resultVector;
	
	int resultVectorSize; //result vector
	if (other.size() > coefficients.size()) //deciding witch vector is bigger so it can calculate based on that
		resultVectorSize = other.size();
	else
		resultVectorSize = coefficients.size();

	for (int i = 0; i < resultVectorSize; i++) { 

		//for runs BIGGERVECTOR times and sums values of both vector to the point where smaller 
		//vector doesn't have more values to sum, so it just assings rest of the values of bigger vector

		if (resultVectorSize == other.size()) {
			if (i < coefficients.size())
				resultVector.push_back(coefficients[i] + other[i]);
			else
				resultVector.push_back(other[i]);
		}
		else {
			if (i < other.size())
				resultVector.push_back(coefficients[i] + other[i]);
			else
				resultVector.push_back(coefficients[i]);
		}
	}

	Polynomial result = Polynomial(resultVector); //creates new polynomial object for new vector...

	return result; //...and returns
}

void Polynomial::PrintoutOfPolynomial() {

	int iterrations = 0;
	for (double c : coefficients) {

		if (c == 0) {
			iterrations++;
			continue;
		}
		else {
			
			if(iterrations != 0)
				cout << " + ";

			if (c < 0)
				cout << "(" << c << ") ";
			else
				cout << c << " ";

			cout << "* x^" << iterrations;

			iterrations++;
		}

		
	}
	
}
