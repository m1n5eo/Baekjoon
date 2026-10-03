#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct type {
    string name;
    int korean, english, math;
};

int n;
vector<type> v;

bool compare(type a, type b) {
    if(a.korean != b.korean) return a.korean > b.korean;
    else if(a.english != b.english) return a.english < b.english;
    else if(a.math != b.math) return a.math > b.math;
    else return a.name < b.name;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        int a, b, c;

        cin >> str >> a >> b >> c;

        v.push_back({str, a, b, c});
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i].name << "\n";
    }
}