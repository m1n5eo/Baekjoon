#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "수를 출력할 때는 따옴표를 생략합니다." << "\n";
	cout << 123 << "\n";
	cout << showpoint << setprecision(7) << 6.500000 << "\n";
}