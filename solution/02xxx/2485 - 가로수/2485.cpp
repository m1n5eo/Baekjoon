#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111111

int n, save;
vector<int> v;

bool compare(int a, int b) {
    return a < b;
}

int FindGCD(int a, int b) {
    if(b == 0) return a;
    return FindGCD(b, a%b);
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(i != 0) v.push_back(temp-save);

        save = temp;
    }

    sort(v.begin(), v.end(), compare);

    int gcd = v[0], result = 0;

    for(int i = 1; i < n-1; i++) {
        gcd = FindGCD(gcd, v[i]);
    }

    for(int i = 0; i < n-1; i++) {
        result += v[i]/gcd-1;
    }

    cout << result;
}