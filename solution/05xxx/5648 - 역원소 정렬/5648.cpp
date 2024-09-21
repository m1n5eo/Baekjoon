#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(long long int a, long long int b) {
    return a < b;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    long long int temp;
    vector<long long int> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;

        long long int k = 0;

        while(temp) {
            k = k*10 + temp%10;
            temp = temp/10;
        }

        v.push_back(k);
    }

    sort(v.begin(), v.end(), compare);

    int len = v.size();

    for(int i = 0; i < len; i++) {
        cout << v[i] << "\n";
    }
    
    return 0;
}