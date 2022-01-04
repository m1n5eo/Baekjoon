#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0, petya, vasya, tonya;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> petya >> vasya >> tonya;
        if(petya && vasya) cnt++;
        else if(vasya && tonya) cnt++;
        else if(petya && tonya) cnt++;
    }
    cout << cnt;
}