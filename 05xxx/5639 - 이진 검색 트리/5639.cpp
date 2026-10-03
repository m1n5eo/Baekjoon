#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int x;
vector<int> vec(1, 0);

void solve(int left, int right) {
    if(left > right) return;
    else if(left == right) {
        cout << vec[left] << " ";
        return;
    }
    for(int i = left+1; i <= right; i++) {
        if(vec[left] < vec[i]) {
            solve(left+1, i-1);
            solve(i, right);
            cout << vec[left] << " ";
            break;
        }
        else if(right == i) {
            solve(left+1, right);
            cout << vec[left] << " ";
            break;
        }
    }
}

int main() {
    FASTIO
    while(cin >> x) vec.push_back(x);
    solve(1, vec.size()-1);
}