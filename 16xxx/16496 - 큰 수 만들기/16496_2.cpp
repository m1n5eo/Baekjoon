#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, cnt;
string temp;
vector<string> v;

bool compare(string a, string b) {
    return stoull(a+b) > stoull(b+a);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        
        if(temp == "0") cnt += 1;
    }

    if(cnt == n) cout << 0;
    else {
        sort(v.begin(), v.end(), compare);
        for(int i = 0; i < n; i++) {
            cout << v[i];
        }
    }
}