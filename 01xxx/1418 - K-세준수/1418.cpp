#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, k;

    cin >> n >> k;

    vector<int> prime;
    vector<bool> check(n+1, false);

    check[0] = true;
    check[1] = true;

    for(int i = 2; i <= n; i++) {
        if(check[i] == false) {
            if(i > k) prime.push_back(i);
            for(int j = i*2; j <= n; j+=i) {
                check[j] = true;
            }
        }
    }

    int prime_size = prime.size(), cnt = 0;

    for(int i = 1; i <= n; i++) {
        bool stop_point = true;

        for(int j = 0; j < prime_size && prime[j] <= i && stop_point; j++) {
            if(i%prime[j] == 0) {
                stop_point = false;
                break;
            }
        }

        if(stop_point == true) cnt += 1;
    }

    cout << cnt;
}