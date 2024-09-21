#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int main() {
    FASTIO

    int n, temp;
    vector<int> vec, result(MAX, -1);
    stack<int> st;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        while(st.size() && vec[st.top()] < vec[i]) {
            result[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}