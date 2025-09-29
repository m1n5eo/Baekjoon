#include <iostream>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

vector<bool> square(MAX*2, false);

void init() {
    for(int i = 2; i*i < MAX*2; i++) square[i*i] = true;
}

deque<int> solve() {
    int n;
    cin >> n;
    deque<int> ret;
    ret.push_back(1);
    for(int i = 2; i <= n; i++) {
        if(square[ret.back() + i] == false) ret.push_back(i);
        else if(square[ret.front() + i] == false) ret.push_front(i);
        else return {-1};
    }
    return ret;
}

int main() {
    FASTIO
    init();
    int tc; cin >> tc;
    while(tc--) {
        for(int sol : solve()) cout << sol << " ";
        cout << "\n";
    }
}