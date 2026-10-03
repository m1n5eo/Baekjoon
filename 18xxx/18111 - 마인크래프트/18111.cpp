#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1000000000
#define MAX 255555

bool compare(int a, int b) {
    return a > b;
}

int main() {
    FASTIO

    int n, m, b, idx, temp;
    lli time, result = INF;
    vector<int> block;

    cin >> n >> m >> b;

    n *= m;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        block.push_back(temp);
    }

    sort(block.begin(), block.end(), compare);

    for(int k = 0; k <= 256; k++) {
        temp = b;
        time = 0;

        for(int i = 0; i < n; i++) {
            if(block[i] > k) {
                time += (block[i]-k)*2;
                temp += block[i]-k;
            }
            else if(block[i] < k) {
                if(temp-(k-block[i]) < 0) {
                    time = INF;
                    break;
                }

                time += k-block[i];
                temp -= k-block[i];
            }
        }
        
        if(time <= result) {
            result = time;
            idx = k;
        }
    }
    
    cout << result << " " << idx;
}