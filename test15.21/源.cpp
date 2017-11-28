#include"Graph.h"
#include<iostream>
using namespace std;
int main() {
	Rectangle rec(3, 4);
	Sphere sph(3.4);
	cout << rec.ger_area() << endl;
	cout << sph.get_volume() << endl;
	system("pause");
	return 0;
}