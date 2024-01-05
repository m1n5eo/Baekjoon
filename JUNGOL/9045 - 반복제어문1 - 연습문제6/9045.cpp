#include <iostream>
using namespace std;

int main() {
    int num;
    while(1) {
        cout << "1. 입력하기" << "\n";
        cout << "2. 출력하기" << "\n";
        cout << "3. 삭제하기" << "\n";
        cout << "4. 끝내기" << "\n";
        cout << "작업할 번호를 선택하세요. ";

        cin >> num;

        if(num == 1) cout << "\n" << "입력하기를 선택하였습니다." << "\n\n";
        else if(num == 2) cout << "\n" << "출력하기를 선택하였습니다." << "\n\n";
        else if(num == 3) cout << "\n" << "삭제하기를 선택하였습니다." << "\n\n";
        else if(num == 4) {
            cout << "\n" << "끝내기를 선택하였습니다.";
            break;
        }
        else cout << "\n" << "잘못 입력하였습니다." << "\n\n";
    }
}
