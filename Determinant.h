#include <iostream>

template <class T>
class Determinant
{
private:
	T array;
	int determinantWH;
	float GaussJordan(T array);
	float Sarruss(T array);
public:
	Determinant(T array, int dWH);
	float CalculateDeterminant();
	void Printout();
};

template<class T>
Determinant<T>::Determinant(T Iarray, int size) {
	this->determinantWH = size;
	array = Iarray;
}

template <class T>
void Determinant<T>::Printout() {

	for (int i = 0; i < determinantWH; i++) {
		for (int j = 0; j < determinantWH; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template <class T>
float Determinant<T>::CalculateDeterminant() {
	if (determinantWH > 3)
		return (GaussJordan(this->array));
	else
		return (Sarruss(this->array));
}

template <class T>
float Determinant<T>::GaussJordan(T array) {
	
	for (int i = 0; i < this->determinantWH-1; i++) {
		float pivot = array[i][i];
		if (pivot == 0)
			continue;
		for (int j = i+1; j < this->determinantWH; j++) {
			float ratio = (-array[j][i]) / array[i][i];
			for (int c = i; c < this->determinantWH; c++) {
				array[j][c] = array[i][c] * ratio + array[j][c];
			}
				
		}
	}

	float determinant = 1;
	for (int i = 0; i < determinantWH; i++) {
		determinant *= array[i][i];
	}
	return determinant;
}

template <class T>
float Determinant<T>::Sarruss(T array) {

	int sumFromRight = 0;
	int sumFromLeft = 0;

	for (int i = 0; i < 3; i++) {
		int product = 1;
		int ii = i;
		for (int j = 0; j < 3; j++) {
			product *= array[ii][j];
			ii++;
			if (ii > 2) {
				ii = 0;
			}
		}
		sumFromRight += product;
	}

	for (int i = 0; i < 3; i++) {
		int product = 1;
		int ii = i;
		for (int j = 2; j >= 0; j--) {
			product *= array[ii][j];
			ii++;
			if (ii > 2) {
				ii = 0;
			}
		}
		sumFromLeft += product;
	}
	return (sumFromRight - sumFromLeft);
}
