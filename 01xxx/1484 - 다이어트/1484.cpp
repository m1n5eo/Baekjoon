#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> solution() {
    int n; cin >> n;
    vector<int> result;
    int left = 1, right = 2;
    while((left+1)*(left+1) - left*left <= n) {
        if(left == right) right += 1;
        else if(right*right - left*left == n) {
            result.push_back(right);
            left += 1;
        }
        else if(right*right - left*left < n) right += 1;
        else left += 1;
    }
    if(result.empty()) result.push_back(-1);
    return result;
}

int main() {
    FASTIO
    for(int sol : solution()) cout << sol << "\n";
}