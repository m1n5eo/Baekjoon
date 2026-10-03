#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 33

int main() {
    FASTIO

    int n, result = 0;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        string word;
        vector<bool> count(MAX, false);
        bool stop = true;

        cin >> word;

        int word_size = word.size();

        for(int i = 0; i < word_size && stop; i++) {
            if(count[word[i]-'a'] == false) count[word[i]-'a'] = true;
            else if(word[i]-'a' != word[i-1]-'a') stop = false;
        }

        if(stop == true) result += 1;
    }

    cout << result;
}
