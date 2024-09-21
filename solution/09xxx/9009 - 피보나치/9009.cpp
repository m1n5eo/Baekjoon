#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111111

vector<int> fibo;

int main() {
    FASTIO

    fibo.push_back(1);
    fibo.push_back(2);

    for(int cnt = 2; fibo[cnt-1]+fibo[cnt-2] < MAX; cnt++) {
        fibo.push_back(fibo[cnt-1]+fibo[cnt-2]);
    }

    int t, fibo_size = fibo.size();

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int n;
        stack<int> result;

        cin >> n;
        
        for(int i = fibo_size-1; i >= 0; i--) {
            if(n >= fibo[i]) {
                n -= fibo[i];
                result.push(fibo[i]);
            }

            if(n == 0) break;
        }

        while(result.size()) {
            cout << result.top() << " ";
            result.pop();
        }

        cout << "\n";
    }
}