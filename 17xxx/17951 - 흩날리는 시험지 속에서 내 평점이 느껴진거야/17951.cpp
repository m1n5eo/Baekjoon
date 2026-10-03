#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solution() {
    int n, k;
    cin >> n >> k;
    vector<int> score(n);
    for(int i = 0; i < n; i++) cin >> score[i];

    int left = 0, right = 20*100000, result = 0;
    while(left <= right) {
        int mid = (left+right)/2;
        int sum = 0, count = 0;
        for(int i = 0; i < n; i++) {
            if(score[i] + sum < mid) sum += score[i];
            else if(score[i] + sum >= mid) {
                count += 1;
                sum = 0;
            }
        }
        if(count >= k) {
            result = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    return result;
}

int main() {
    FASTIO
    cout << solution();
}