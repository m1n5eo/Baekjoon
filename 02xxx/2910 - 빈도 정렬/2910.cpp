#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

map<string, pair<int, int>> m;

bool compare(string a, string b) {
    if(m[a].first != m[b].first) return m[a].first > m[b].first;
    else return m[a].second < m[b].second;
}

int main() {
    FASTIO
    
    int n, c;
    string num;
    vector<string> number;

    cin >> n >> c;

    for(int i = 0; i < n; i++) {
        cin >> num;

        if(m.find(num) != m.end()) m[num].first += 1;
        else {
            m.insert({num, {1, i}});
            number.push_back(num);
        }
    }

    sort(number.begin(), number.end(), compare);

    int number_size = number.size();

    for(int i = 0; i < number_size; i++) {
        for(int j = 0; j < m[number[i]].first; j++) {
            cout << number[i] << " ";
        }
    }
}