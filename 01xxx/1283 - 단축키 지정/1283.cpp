#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

int main() {
    FASTIO

    int n;
    string o, dummy;
    vector<pair<string, int>> option;
    bool check[33] = {false, };

    cin >> n;
    getline(cin, dummy);

    for(int i = 0; i < n; i++) {
        getline(cin, o);

        int o_size = o.size();
        bool stop_point = true;

        for(int i = 0; i < o_size && stop_point; i++) {
            if(o[i] == ' ') continue;
            else if(i == 0 || o[i-1] == ' ') {
                if('a' <= o[i] && o[i] <= 'z' && check[o[i]-'a'] == false) {
                    option.push_back({o, i});
                    
                    check[o[i]-'a'] = true;
                    stop_point = false;
                }
                else if('A' <= o[i] && o[i] <= 'Z' && check[o[i]-'A'] == false) {
                    option.push_back({o, i});

                    check[o[i]-'A'] = true;
                    stop_point = false;
                }
            }
        }

        for(int i = 0; i < o_size && stop_point; i++) {
            if(i == 0 || o[i] == ' ' || o[i-1] == ' ') continue;
            else {
                if('a' <= o[i] && o[i] <= 'z' && check[o[i]-'a'] == false) {
                    option.push_back({o, i});
                    
                    check[o[i]-'a'] = true;
                    stop_point = false;
                }
                else if('A' <= o[i] && o[i] <= 'Z' && check[o[i]-'A'] == false) {
                    option.push_back({o, i});

                    check[o[i]-'A'] = true;
                    stop_point = false;
                }
            }
        }

        if(stop_point == true) {
            option.push_back({o, INF});
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(option[i].second == INF) {
            cout << option[i].first << "\n";
            continue;
        }

        int option_size = option[i].first.size();

        for(int j = 0; j < option_size; j++) {
            if(j == option[i].second) {
                cout << "[";
                cout << option[i].first[j];
                cout << "]";
            }
            else {
                cout << option[i].first[j];
            }
        }

        cout << "\n";
    }
}