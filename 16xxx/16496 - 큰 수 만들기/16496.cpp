#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, cnt;
string temp;
vector<string> v;

unsigned long long int string_to_int(string str1, string str2) {
    int str1_len = str1.size(), str2_len = str2.size();
    unsigned long long int rtn = 0;

    for(int i = 0; i < str1_len; i++) {
        rtn = rtn*10 + (str1[i]-'0');
    }
    for(int i = 0; i < str2_len; i++) {
        rtn = rtn*10 + (str2[i]-'0');
    }

    return rtn;
}

bool compare(string a, string b) {
    unsigned long long first = string_to_int(a, b);
    unsigned long long second = string_to_int(b, a);

    return first > second;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        
        if(temp == "0") cnt += 1;
    }

    if(cnt == n) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i];
    }

    return 0;
}