#include <iostream>
using namespace std;

int main() {
	int sum = 0, num = 0;
	while(num++ < 10) {
		sum += num;
	}
	cout << "1부터 10까지의 합 = " << sum << "\n";
	cout << "while문이 끝난 후의 num의 값 = " << num;
}