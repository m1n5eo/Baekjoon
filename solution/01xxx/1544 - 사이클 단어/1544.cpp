#include <iostream>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, cnt = 0;
    map<string, bool> m;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        string word;
        
        cin >> word;

        int word_size = word.size();

        for(int i = 0; i < word_size; i++) {
            if(m.find(word) != m.end()) continue;
            else if(i == word_size-1) {
                m.insert({word, true});
                cnt += 1;
            }

            char temp = word[0];
            word.erase(0, 1);
            word = word+temp;
        }
    }

    cout << cnt;
}