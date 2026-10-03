#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

string solution() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1, vector<int>(0));
    for(int _ = 0; _ < n-1; _++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<lli> comb(n+1, 0);
    for(int i = 3; i <= n; i++) 
        comb[i] = comb[i-1] + (i-1)*(i-2)/2;

    lli D = 0, G = 0;
    for(int i = 1; i <= n; i++) {
        G += comb[graph[i].size()];
        if(graph[i].size() >= 2) {
            for(int j : graph[i]) {
                D += (graph[i].size()-1)*(graph[j].size()-1);
            }
        }
    }
    
    if(D > G*6) return "D";
    else if(D < G*6) return "G";
    else return "DUDUDUNGA";
}

int main() {
    FASTIO
    cout << solution();
}