#include <iostream>
#include <deque>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m;
bool check[MAX];
deque<int> dq;

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp == 0) check[i] = true;
        else check[i] = false;
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(check[i] == true) {
            dq.push_back(temp);
        }
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        dq.push_front(temp);
        cout << dq.back() << " ";
        dq.pop_back();
    }
}