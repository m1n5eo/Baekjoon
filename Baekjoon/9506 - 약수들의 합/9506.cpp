#include <iostream>
#include <queue>
using namespace std;

int n, arr[111111];
queue<int> save;

int main() {
    while(1) {
        cin >> n;
        if(n == -1) break;
        else if(arr[n] && arr[n] != n) cout << n << " is NOT perfect.\n";
        else {
            int sum = 0;
            for(int i = 1; i <= n/2; i++) {
                if(n%i) continue;
                else {
                    sum += i;
                    save.push(i);
                }
            }
            arr[n] = sum;
            if(sum != n) cout << n << " is NOT perfect.\n";
            else {
                cout << n << " = ";
                int len = save.size();
                for(int i = 0; i < len; i++) {
                    cout << save.front();
                    if(i != len-1) cout << " + ";
                    else cout << "\n";
                    save.pop();
                }
            }
            while(!save.empty()) save.pop();
        }
    }
}