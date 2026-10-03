#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 111

int main() {
    FASTIO

    int n, start = -1;
    lli temp;
    vector<lli> vec;
    vector<bool> check(MAX, false);
    map<lli, bool> m;
    deque<int> result;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;

        vec.push_back(temp);
        m.insert({temp, true});
    }

    for(int i = 0; i < n; i++) {
        if(m.find(vec[i]*3) == m.end() && ((vec[i]%2 == 0 && m.find(vec[i]/2) == m.end()) || (vec[i]%2 == 1))) {
            start = i;
            break;
        }
    }

    result.push_back(start);
    check[start] = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check[j] == true) continue;

            if(vec[result.back()]%3 == 0 && vec[result.back()]/3 == vec[j]) {
                result.push_back(j);
                check[j] = true;
            }
            else if(vec[result.back()]*2 == vec[j]) {
                result.push_back(j);
                check[j] = true;
            }
        }
    }

    while(result.size()) {
        cout << vec[result.front()] << " ";
        result.pop_front();
    }
}