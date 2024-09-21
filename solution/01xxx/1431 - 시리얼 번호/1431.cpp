#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
    int len1 = a.length(), len2 = b.length();

    if(len1 != len2) {
        return len1 < len2;
    }
    else if(len1 == len2) {
        int sum1 = 0, sum2 = 0;
        
        for(int i = 0; i < len1; i++) {
            if('0' <= a[i] && a[i] <= '9') {
                sum1 += a[i]-'0';
            }
        }
        for(int i = 0; i < len2; i++) {
            if('0' <= b[i] && b[i] <= '9') {
                sum2 += b[i]-'0';
            }
        }

        if(sum1 != sum2) {
            return sum1 < sum2;
        }
        else if(sum1 == sum2) {
            return a < b;
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string str;
    vector<string> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}