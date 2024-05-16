#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int n, m, temp, result, s;
vector<long long int> sum;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        sum.push_back(0);
        for(int j = 0; j < m; j++) {
            cin >> temp;
            sum[i] += temp;
        }
    }

    sort(sum.begin(), sum.end());

    for(int i = 0; i < n; i++) {
        s = s+sum[i];
        result = result+s;
    }

    cout << result;

    return 0;
}