#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout.width(10);
	cout << right << "item";
	cout.width(10);
	cout << right << "count";
	cout.width(10);
	cout << right << "price" << "\n";
	cout.width(10);
	cout << right << "pen";
	cout.width(10);
	cout << right << "20";
	cout.width(10);
	cout << right << "100" << "\n";
	cout.width(10);
	cout << right << "note";
	cout.width(10);
	cout << right << "5";
	cout.width(10);
	cout << right << "95" << "\n";
	cout.width(10);
	cout << right << "eraser";
	cout.width(10);
	cout << right << "110";
	cout.width(10);
	cout << right << "97";
}