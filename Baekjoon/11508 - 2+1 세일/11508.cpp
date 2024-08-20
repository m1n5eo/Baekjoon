#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, result;
vector<int> v;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    FASTIO
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i+=3) {
        if(i+1 < n) result += v[i]+v[i+1];
        else result += v[i];
    }

    cout << result;
}