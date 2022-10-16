#include <iostream>
#include "Polynomial.h"

int main()
{
	std::vector<double> vectorOne = {5,2,7,4,5,6,5};
	Polynomial p = Polynomial(vectorOne);
	cout << "First polynomial \n";
	p.PrintoutOfPolynomial();
	cout << endl;

	std::vector<double> vectorTwo = {1,-3,9,0,4};
	Polynomial o = Polynomial(vectorTwo);
	cout << "Second polynomial \n";
	o.PrintoutOfPolynomial();
	cout << endl;

	Polynomial r = p.Add(o); //result polynomial r = p + o

	//r polynomial -> {6, -1, 16, 4, 9, 6, 5}

	cout << "Printout of result polynomial\n";
	r.PrintoutOfPolynomial();
	cout << endl << endl;

	cout << "If index out of range -> " << r.GetOneCoefficient(10) << "\n";
	cout << "If index in range -> " << r.GetOneCoefficient(4) << "\n";

	cout << "Degree of polynomial -> " << r.GetDegree() << "\n";
	cout << "Value of polynomial -> " << r.GetValueOfPolynomial(3) << "\n";
	

}
