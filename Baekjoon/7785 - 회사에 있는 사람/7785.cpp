#include <iostream>
#include <map>
#include <stack>
using namespace std;

int n;
string name, status;
map<string, string> m;
stack<string> st;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name >> status;

        if(status == "enter") {
            if(m.find(name) == m.end()) {
                m.insert({name, status});
            }
        }
        else if(status == "leave") {
            if(m.find(name) != m.end()) {
                m.erase(name);
            }
        }
    }

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        st.push(iter->first);
    }

    while(st.size()) {
        cout << st.top() << "\n";
        st.pop();
    }
}