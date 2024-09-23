#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n;
    vector<int> cal;

    cal.push_back(1);
    cal.push_back(1);
    cal.push_back(2);
    cal.push_back(2);
    cal.push_back(2);
    cal.push_back(8);

    for(int i = 0; i < 6; i++) {
        cin >> n;
        cout << cal[i]-n << " ";
    }
}