#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string solution() {
    int n, now = 1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string contest; cin >> contest;
        now *= contest.size();
    }

    if(now == 232) return "2017";
    else if(now == 88) return "2018";
    else if(now == 754) return "2019";
    else if(now == 29) return "2020";
    else if(now == 28) return "2021";
    else if(now == 1015) return "2022";
    else if(now == 1295) return "2023";
    else if(now == 1073) return "2024";
    else if(now == 348) return "2025";
    else return "Goodbye, ChAOS!";
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) cout << solution() << "\n";
}