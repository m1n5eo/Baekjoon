#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

int t;

int main() {
    FASTIO

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int k, n, min_num = INF, max_num = 0;
        vector<int> v;
        vector<bool> check;

        cin >> k >> n;

        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            max_num = max(max_num, temp);

            v.push_back(temp);
            check.push_back(false);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(v[i] < v[j]) {
                    check[j] = true;
                    min_num = min(min_num, v[j]);
                }
                else if(min_num < v[j]) {
                    check[j] = true;
                }
            }
        }

        if(v[n-1] > min_num) {
            check[n-1] = true;
        }

        int result = 0;

        for(int i = 0; i < n; i++) {
            if(check[i] == true) {
                result += 1;
            }
        }
        
        cout << k << " " << result << "\n";
    }
    
    return 0;
}