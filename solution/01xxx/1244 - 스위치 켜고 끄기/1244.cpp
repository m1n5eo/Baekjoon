#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int main() {
    FASTIO
    
    int n, m, temp, gen, num;
    vector<bool> value(MAX, false);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> temp;

        if(temp == 0) value[i] = false;
        else if(temp == 1) value[i] = true;
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> gen >> num;

        if(gen == 1) {
            for(int i = num; i <= n; i+=num) {
                value[i] = !value[i];
            }
        }
        else if(gen == 2) {
            int start = num, end = num;

            while(start != 1 && end != n) {
                if(value[start-1] != value[end+1]) {
                    break;
                }
                
                start -= 1;
                end += 1;
            }

            for(int k = start; k <= end; k++) {
                value[k] = !value[k];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(value[i] == true) cout << 1 << " ";
        else if(value[i] == false) cout << 0 << " ";

        if(i%20 == 0) {
            cout << "\n";
        }
    }
}