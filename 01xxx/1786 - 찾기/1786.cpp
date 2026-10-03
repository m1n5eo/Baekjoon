#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX 1111111

string str, cmp;
int failure[MAX];
queue<int> result;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    getline(cin, str);
    getline(cin, cmp);

    int j, cmp_size = cmp.size();

    failure[0] = -1;
    for(int i = 1; i < cmp_size; i++) {
        j = failure[i-1];

        while(cmp[i] != cmp[j+1] && j >= 0) {
            j = failure[j];
        }

        if(cmp[i] == cmp[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    int i = 0; j = 0;
    int str_size = str.size();

    while(i < str_size && j < cmp_size) {
        if(str[i] == cmp[j]) {
            i += 1;
            j += 1;
        }
        else if(j == 0) {
            i += 1;
        }
        else {
            j = failure[j-1]+1;
        }

        if(j == cmp_size) {
            result.push(i-cmp_size+1);
            j = failure[j-1]+1;
        }
    }

    cout << result.size() << "\n";
    while(result.size()) {
        cout << result.front() << " ";
        result.pop();
    }
}