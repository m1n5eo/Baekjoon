#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n;
    string input;
    vector<string> name;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input;
        name.push_back(input);
    }

    vector<string> temp = name;

    sort(temp.begin(), temp.end());

    for(int i = 0; i < n; i++) {
        if(name[i] != temp[i]) break;
        else if(i == n-1) {
            cout << "INCREASING";
            exit(0);
        }
    }

    for(int i = 0; i < n; i++) {
        if(name[i] != temp[n-i-1]) break;
        else if(i == n-1) {
            cout << "DECREASING";
            exit(0);
        }
    }

    cout << "NEITHER";
}