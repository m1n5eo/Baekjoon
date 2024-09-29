#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 33

int main() {
    FASTIO

    int n, m;
    char x, y;
    string connect;
    vector<vector<bool>> graph(MAX, vector<bool>(MAX, false));

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> x >> connect >> y;
        graph[x-'a'][y-'a'] = true;
    }

    for(int k = 0; k < MAX; k++) {
        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < MAX; j++) {
                if(graph[i][k] == true && graph[k][j] == true) {
                    graph[i][j] = true;
                }
            }
        }
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> connect >> y;

        if(graph[x-'a'][y-'a'] == true) cout << "T" << "\n";
        else if(graph[x-'a'][y-'a'] == false) cout << "F" << "\n";
    }
}