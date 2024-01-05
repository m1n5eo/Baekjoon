#include <iostream>
using namespace std;

int main() {
	int score;
	while(1) {
		cout << "점수를 입력하세요. ";
		cin >> score;
		if(!(0 <= score && score <= 100)) break;
		else if(score < 80) cout << "죄송합니다. 불합격입니다." << "\n";
		else cout << "축하합니다. 합격입니다." << "\n";
	}
}