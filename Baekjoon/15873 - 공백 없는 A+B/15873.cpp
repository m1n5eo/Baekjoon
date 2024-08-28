#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    string num;

    cin >> num;

    if(10 <= stoi(num) && stoi(num) <= 99) cout << num[0]-'0' + num[1]-'0';
    else if(100 <= stoi(num) && stoi(num) <= 999) {
        string k = "";
        k = k + num[0] + num[1];

        if(stoi(k) == (num[0]-'0')*10 + num[1]-'0' && num[2] != '0') cout << (num[0]-'0')*10 + num[1]-'0' + num[2]-'0';
        else cout << num[0]-'0' + (num[1]-'0')*10 + num[2]-'0';
    }
    else cout << (num[0]-'0')*10 + num[1]-'0' + (num[2]-'0')*10 + num[3]-'0';
}