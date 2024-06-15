#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int _ = 0; _ < t; _++) {
        vector<int> fibo;
        int n, mod, cnt = 0;

        fibo.push_back(0);
        fibo.push_back(0);
        fibo.push_back(1);

        cin >> n >> mod;

        while(true) {
            fibo[0] = fibo[1];
            fibo[1] = fibo[2];
            fibo[2] = (fibo[0]+fibo[1])%mod;

            if(fibo[1] == 0 && fibo[2] == 1) {
                cout << n << " " << cnt+1 << "\n";
                break;
            }

            cnt += 1;
        }
    }
}