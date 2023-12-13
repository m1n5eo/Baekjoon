#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.size(), cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < len-2; i++) {
        if(str[i] == 'K' && str[i+1] == 'O' && str[i+2] == 'I') cnt1++;
        else if(str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I') cnt2++;
    }
    cout << cnt1 << "\n" << cnt2;
}