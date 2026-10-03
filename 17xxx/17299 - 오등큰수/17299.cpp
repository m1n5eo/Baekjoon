#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int main() {
    FASTIO

    int n, temp;
    vector<int> vec, result(MAX, -1), cnt(MAX, 0);
    stack<int> st;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;

        vec.push_back(temp);
        cnt[temp] += 1;
    }

    for(int i = 0; i < n; i++) {
        while(st.size() && cnt[vec[st.top()]] < cnt[vec[i]]) {
            result[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}