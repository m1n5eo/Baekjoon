#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    vector<string> vec = {"000", "001", "010", "011", "100", "101", "110", "111"};
    string scan;

    cin >> scan;

    int scan_size = scan.size();
    
    for(int i = 0; i < scan_size; i++) {
        if(i != 0) cout << vec[scan[i]-'0'];
        else {
            if(scan[i]-'0' == 0) cout << "0";
            else if(scan[i]-'0' == 1) cout << "1";
            else if(scan[i]-'0' == 2) cout << "10";
            else if(scan[i]-'0' == 3) cout << "11";
            else cout << vec[scan[i]-'0'];
        }
    }
}