#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n;
    string file;
    map<string, int> m;
    vector<string> extension;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> file;

        file.erase(0, file.find(".")+1);
        
        if(m.find(file) != m.end()) m[file] += 1;
        else {
            m.insert({file, 1});
            extension.push_back(file);
        }
    }

    sort(extension.begin(), extension.end());

    int extension_size = extension.size();

    for(int i = 0; i < extension_size; i++) {
        cout << extension[i] << " " << m[extension[i]] << "\n";
    }
}