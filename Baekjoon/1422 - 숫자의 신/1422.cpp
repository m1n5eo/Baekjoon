#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define ulli unsigned long long int

int n, k;
string add = "1";
vector<string> v;

bool compare(string a, string b) {
    return stoull(a+b) > stoull(b+a);
}

int main() {
    FASTIO

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        v.push_back(temp);

        if(stoull(add) < stoull(temp)) {
            add = temp;
        }
    }

    for(int i = 0; i < k-n; i++) {
        v.push_back(add);
    }
    
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < k; i++) {
        cout << v[i];
    }
}