#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, result;

void egg(int idx, int cnt, vector<int> durability, vector<int> weight) {
    result = max(result, cnt);

    for(int i = 0; i < n; i++) {
        if(i != idx && durability[i] > 0) {
            durability[i] -= weight[idx];
            durability[idx] -= weight[i];

            if(durability[i] <= 0 && durability[idx] <= 0) result = max(result, cnt+2);
            else if(durability[i] <= 0 || durability[idx] <= 0) result = max(result, cnt+1);

            for(int j = idx+1; j < n; j++) {
                if(durability[j] > 0) {
                    if(durability[i] <= 0 && durability[idx] <= 0) egg(j, cnt+2, durability, weight);
                    else if(durability[i] <= 0 || durability[idx] <= 0) egg(j, cnt+1, durability, weight);
                    else egg(j, cnt, durability, weight);

                    break;
                }
            }

            durability[i] += weight[idx];
            durability[idx] += weight[i];
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    vector<int> durability(n+1, 0), weight(n+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> durability[i] >> weight[i];
    }

    egg(0, 0, durability, weight);

    cout << result;
}