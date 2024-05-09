#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int node[3][33];
string res[3] = {"", "", ""};

void dfs(int idx) {
    char temp = (char)(idx+'A'-1);

    res[0] = res[0]+temp;

    if(node[1][idx] != 0) {
        dfs(node[1][idx]);
    }

    res[1] = res[1]+temp;

    if(node[2][idx] != 0) {
        dfs(node[2][idx]);
    }

    res[2] = res[2]+temp;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char root, left, right;

        cin >> root >> left >> right;

        if(left != '.') {
            node[0][left-'A'+1] = root-'A'+1;
            node[1][root-'A'+1] = left-'A'+1;
        }
        if(right != '.') {
            node[0][right-'A'+1] = root-'A'+1;
            node[2][root-'A'+1] = right-'A'+1;
        }
    }

    dfs(1);

    for(int i = 0; i < 3; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}