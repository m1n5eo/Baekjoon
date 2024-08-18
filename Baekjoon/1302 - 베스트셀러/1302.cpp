#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n;
    map<string, int> m;
    vector<string> book;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string title;

        cin >> title;

        if(m.find(title) != m.end()) m[title] += 1;
        else {
            m.insert({title, 1});
            book.push_back(title);
        }
    }

    int book_size = book.size();
    pair<string, int> bookMax = {book[0], m[book[0]]};

    for(int i = 1; i < book_size; i++) {
        if(bookMax.second < m[book[i]]) bookMax = {book[i], m[book[i]]};
        else if(bookMax.second == m[book[i]] && bookMax.first > book[i]) bookMax = {book[i], m[book[i]]};
    }

    cout << bookMax.first;
}