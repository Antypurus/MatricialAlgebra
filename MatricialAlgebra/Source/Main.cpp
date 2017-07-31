#include"Vector\Vector.h"
#include<iostream>

using namespace std;
using namespace MatricialAlgebra;

void main() {
	Vector< int> a(2);

	a[0] = 4;
	a[1] = 5;

	Vector< int> b(2);
	b[0] = 6;
	b[1] = 5;

	auto res = a*2;

	cout << "x:" << res[0] << '\n';
	cout << "y:" << res[1] << '\n';

	system("pause");
}