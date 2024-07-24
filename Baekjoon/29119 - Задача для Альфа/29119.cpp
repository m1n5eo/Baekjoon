#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
vector<string> v;

bool compare(string a, string b) {
    return stoull(a+b) > stoull(b+a);
}

int main() {
    FASTIO

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}