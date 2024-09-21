#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<string> v;
string str;

bool compare(string a, string b) {
    return a+b > b+a;
}

int main() {
    FASTIO

    while(cin >> str) {
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(), compare);

    int vSize = v.size();

    for(int i = 0; i < vSize; i++) {
        cout << v[i];
    }
}