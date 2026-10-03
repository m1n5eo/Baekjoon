#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct type {
    string str;
    int idx, len;
};

int n, max_len, start_idx, end_idx = 1, save_idx = 1234567890;
bool check;
string prt_first, prt_second;
vector<type> v;
deque<pair<int, int>> dq;

bool compare1(type a, type b) {
    return a.str < b.str;
}

bool compare2(type a, type b) {
    return a.idx < b.idx;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        v.push_back({temp, i});
    }

    sort(v.begin(), v.end(), compare1);

    for(int i = 0; i < n-1; i++) {
        int str_size = min(v[i].str.size(), v[i+1].str.size());
        int cnt = 0;

        for(int j = 0; j < str_size; j++) {
            if(v[i].str[j] == v[i+1].str[j]) cnt += 1;
            else break;
        }

        v[i].len = cnt;

        if(cnt > max_len) {
            while(dq.size()) dq.pop_front();

            max_len = cnt;
            start_idx = i;
            end_idx = i+1;
            check = true;
        }
        else if(max_len == cnt && check == false) {
            max_len = cnt;
            start_idx = i;
            end_idx = i+1;
            check = true;
        }
        else if(cnt == v[i-1].len && check == true) {
            end_idx += 1;
        }
        else {
            check = false;
            if(i != 0 && v[i-1].len == max_len) {
                dq.push_back({start_idx, end_idx});
            }
        }
    }

    if(dq.size() == 0) {
        dq.push_back({start_idx, end_idx});
    }
    else if(dq.back().first != start_idx && v[dq.back().first].len == v[start_idx].len) {
        dq.push_back({start_idx, end_idx});
    }

    while(dq.size()) {
        sort(v.begin()+dq.front().first, v.begin()+dq.front().second+1, compare2);

        if(save_idx > v[dq.front().first].idx) {
            save_idx = v[dq.front().first].idx;
            prt_first = v[dq.front().first].str;
            prt_second = v[dq.front().first+1].str;
        }

        dq.pop_front();
    }

    cout << prt_first << "\n" << prt_second;
}