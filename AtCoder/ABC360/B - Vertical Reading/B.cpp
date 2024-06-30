#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string s, t;

int main() {
    FASTIO
    
    cin >> s >> t;

    int s_size = s.size();

    for(int i = 0; i < s_size; i++) {
        if(s[i] == t[0]) {
            int c = i+1;

            for(int w = i+1; w < s_size; w++) {
                string cmp = "";

                for(int j = i; j < s_size; j+=w) {
                    cmp += s[j];
                }

                if(cmp == t) {
                    cout << "Yes";
                    exit(0);
                }
            }
        }
    }
    
    cout << "No";
}