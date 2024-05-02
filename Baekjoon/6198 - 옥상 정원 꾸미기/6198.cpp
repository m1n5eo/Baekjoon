#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, temp;
    long long int res = 0;
    stack<pair<int,int>> st;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;

        while(st.size()) {
            if(st.top().first > temp) break;
            else st.pop();
        }

        if(st.size()) {
            st.push({temp, st.top().second+1});
            res += st.top().second;
        }
        else {
            st.push({temp, 0});
        }
    }

    cout << res;

    return 0;
}