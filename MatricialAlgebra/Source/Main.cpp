#include"Vector\Vector.h"
#include<iostream>

using namespace std;
using namespace MatricialAlgebra;

void main() {
	Vector<unsigned int> a(2);

	a[0] = 4;
	a[1] = 5;

	Vector<unsigned int> b(2);
	b[0] = 6;
	b[1] = 5;

	auto res = a + b;

	cout << "x:" << res[0] << '\n';
	cout << "y:" << res[1] << '\n';

	system("pause");
}