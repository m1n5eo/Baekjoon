#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111
#define INF 2100000000

int n, cnt;
vector<int> arr, v, LIS;
stack<int> st;

int main() {
    FASTIO
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        if(i == 0 || v.back() < arr[i]) {
            v.push_back(arr[i]);
            LIS.push_back(v.size());
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
            LIS.push_back(idx+1);
        }
    }
    
    int key = v.size();

    for(int i = n-1; i >= 0; i--) {
        if(key == LIS[i]) {
            st.push(arr[i]);
            key -= 1;
        }
    }

    cout << v.size() << "\n";
    
    while(st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
}