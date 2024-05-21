#include <iostream>
#include <cmath>
using namespace std;

long long int n, m, temp, start_point, cnt, idx, sqrt_n, sqrt_m;
bool check[1111111], prime[1111111] = {true, true, };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 2; i < 1111111; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < 1111111; j+=i) {
                prime[j] = true;
            }
        }
    }

    cin >> n >> m;

    sqrt_m = sqrt(m), idx = n;

    for(long long int i = 2; i <= sqrt_m; i++) {
        if(prime[i] == true) continue;

        temp = i*i;

        if(n/temp > 0) start_point = n/temp*temp;
        else start_point = temp;

        for(long long int j = start_point; j <= m; j+=(i*i)) {
            if(j-idx < 0) continue;
            check[j-idx] = true;
        }
    }

    for(long long int i = n-idx; i <= m-idx; i++) {
        if(check[i] == false) cnt += 1;
    }

    cout << cnt;
    
    return 0;
}