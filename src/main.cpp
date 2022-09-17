#include "../include/place.hpp"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	Place<double> reales;
	reales.add(8.9);
	reales.add(4.3);
	reales.add(4.8);
	int a = 4;
	double *preal = reales.find(
			[](double element)
			{
				cout << element << endl;
				return element == 4.2;
			});
	reales.forEach(
			[](double element)
			{
				cout << element << endl;
			});
	cout << reales[1] << endl;

	cout << reales[1] << endl;

	// reales.~Place();
	int sa;
	return 0;
}

// // Overloading operators for Array class
// #include <cstdlib>
// #include <iostream>

// using namespace std;

// // A class to represent an integer array
// class Array
// {
// private:
// 	int *ptr;
// 	int size;

// public:
// 	Array(int *, int);

// 	// Overloading [] operator to access elements in array style
// 	int &operator[](int);

// 	// Utility function to print contents
// 	void print() const;
// };

// // Implementation of [] operator.  This function must return a
// // reference as array element can be put on left side
// int &Array::operator[](int index)
// {
// 	if (index >= size)
// 	{
// 		cout << "Array index out of bound, exiting";
// 		exit(0);
// 	}
// 	return ptr[index];
// }

// // constructor for array class
// Array::Array(int *p = NULL, int s = 0)
// {
// 	size = s;
// 	ptr = NULL;
// 	if (s != 0)
// 	{
// 		ptr = new int[s];
// 		for (int i = 0; i < s; i++)
// 			ptr[i] = p[i];
// 	}
// }

// void Array::print() const
// {
// 	for (int i = 0; i < size; i++)
// 		cout << ptr[i] << " ";
// 	cout << endl;
// }

// // Driver program to test above methods
// int main()
// {
// 	int a[] = {1, 2, 4, 5};
// 	Array arr1(a, 4);
// 	arr1[3] = 6;
// 	arr1.print();
// 	cout << endl;
// 	int b = arr1[0];
// 	cout << b;
// 	cout << b;
// 	cout << b;
// 	cout << b;
// 	cout << endl;

// 	return 0;
// }
