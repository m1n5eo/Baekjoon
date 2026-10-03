#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct trie {
    trie* str[26];
    bool check;
    trie() {
        check = false;
        for(int i = 0; i < 26; i++) str[i] = NULL;
    }

    void insert(const char* s) {
        if(!*s) {
            check = true;
            return;
        }
        int now = *s - '0';
        if(str[now] == NULL) str[now] = new trie;
        str[now] -> insert(s+1);
    }

    bool search(const char* s) {
        if(!*s) return false;
        else if(check == true) return true;
        int now = *s - '0';
        if(str[now] == NULL) return false;
        return str[now] -> search(s+1);
    }
};

string solve() {
    int n;
    cin >> n;
    vector<string> phone;
    trie* root = new trie;
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        phone.push_back(temp);
        root -> insert(phone[i].c_str());
    }
    
    for(int i = 0; i < n; i++) {
        if(root -> search(phone[i].c_str())) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) cout << solve() << "\n";
}