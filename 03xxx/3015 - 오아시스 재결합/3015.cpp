#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, height;
    long long int res = 0;
    stack<pair<int, pair<int, int>>> st;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> height;

        if(st.size() == 0) {
            st.push({height, {0, 1}});
            res += 0;
        }
        else if(st.size() != 0) {
            if(st.top().first < height) {
                int cnt = 0;

                while(st.size() && st.top().first < height) {
                    cnt += 1;
                    st.pop();
                }
                
                if(st.size() == 0) {
                    st.push({height, {cnt, 1}});
                    res += cnt;
                }
                else if(st.top().first > height) {
                    cnt += 1;
                    st.push({height, {cnt, 1}});
                    res += cnt;
                }
                else if(st.top().first == height) {
                        if(st.size() == st.top().second.second) {
                        cnt += st.top().second.second;
                    }
                        else if(st.size() != st.top().second.second) {
                        cnt += st.top().second.second+1;
                    }

                    st.push({height, {cnt, st.top().second.second+1}});
                    res += cnt;
                }
            }
            else if(st.top().first == height) {
                int cmp1 = st.size(), cmp2 = st.top().second.second;
                int k = min(cmp1, cmp2+1);

                st.push({height, {k, st.top().second.second+1}});
                res += st.top().second.first;
            }
            else if(st.top().first > height) {
                st.push({height, {1, 1}});
                res += 1;
            }
        }
    }

    cout << res;

    return 0;
}