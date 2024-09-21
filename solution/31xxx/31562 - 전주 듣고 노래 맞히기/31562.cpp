#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    string name;
    char note1, note2, note3;
};

int n, m;
vector<type> v;

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int _temp;
        string _name;
        char _note[8];

        cin >> _temp >> _name;
        for(int j = 0; j < 7; j++) {
            cin >> _note[j];
        }

        v.push_back({_name, _note[0], _note[1], _note[2]});
    }

    for(int i = 0; i < m; i++) {
        int cnt = 0, idx = -1;
        char ch[3];

        for(int j = 0; j < 3; j++) cin >> ch[j];

        for(int j = 0; j < n; j++) {
            if(ch[0] == v[j].note1 && ch[1] == v[j].note2 && ch[2] == v[j].note3) {
                cnt += 1;
                idx = j;
            }
        }

        if(cnt == 0) cout << "!\n";
        else if(cnt == 1) cout << v[idx].name << "\n";
        else cout << "?\n";
    }

    return 0;
}