#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, res;
    cin >> n >> k;

    int six, one, six_min = 1111, one_min = 1111;
    for(int i = 0; i < k; i++) {
        cin >> six >> one;

        six_min = min(six_min, six);
        one_min = min(one_min, one);
    }

    res = min(n*one_min, ((n-1)/6+1)*six_min);
    res = min(res, n/6*six_min+n%6*one_min);

    cout << res;

    return 0;
}