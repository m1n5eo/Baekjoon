#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a < b;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> v;
    string str;

    cin >> str;

    int len = str.length();

    for(int i = 0; i < len; i++) {
        v.push_back(str);
        str.erase(0, 1);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < len; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}