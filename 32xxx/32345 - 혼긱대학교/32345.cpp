#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000007

int main() {
    FASTIO

    int t;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        string word;
        lli result = 0, cnt = 0;

        cin >> word;

        for(char words : word) {
            if(words == 'a' || words == 'e' || words == 'i' || words == 'o' || words == 'u') {
                if(result != 0) result = (result*cnt)%MOD;
                else result = 1;              
                cnt = 1;
            }
            else cnt += 1;
        }
        
        if(result != 0) cout << result << "\n";
        else cout << -1 << "\n";
    }
}