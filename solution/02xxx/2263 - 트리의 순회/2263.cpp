#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> inorder, postorder;

void preorder(int inLeft, int inRight, int postLeft, int postRight) {
    if(postLeft > postRight || inLeft > inRight) return;
    
    int root = postorder[postRight];
    cout << root << " ";
    for(int i = inLeft; i <= inRight; i++) {
        if(inorder[i] == root) {
            int left = i - inLeft;
            preorder(inLeft, i-1, postLeft, postLeft+left-1);
            preorder(i+1, inRight, postLeft+left, postRight-1);
            break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        inorder.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        postorder.push_back(temp);
    }

    preorder(0, n-1, 0, n-1);
}

int main() {
    FASTIO
    solve();
}