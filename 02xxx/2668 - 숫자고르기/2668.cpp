#include <bits/stdc++.h>
using namespace std;

int n, cnt, temp, check;
int arr[101][101], visited[101], print[101];
stack<int> arrDelete, arrPrint;

void dfs(int idx) {
    visited[idx] = 1;
    arrDelete.push(idx);
    for(int i = 1; i <= n; i++) {
        if(arr[idx][i] && visited[i] == 0) {
            arrPrint.push(i);
            dfs(i);
        }
        else if(arr[idx][i] && visited[i] == 1 && check == i) {
            arrPrint.push(i);
            while(arrPrint.size()) {
                print[cnt++] = arrPrint.top();
                arrPrint.pop();
            }
            while(arrDelete.size()) arrDelete.pop();
            return;
        }
        else if(arr[idx][i] && visited[i] == 1 && check != i) {
            while(arrDelete.size()) {
                visited[arrDelete.top()] = 0;
                arrDelete.pop();
            }
            while(arrPrint.size()) arrPrint.pop();
            return;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        arr[i][temp] = 1;
    }
    for(int i = 1; i <= n; i++) {
        check = i;
        dfs(i);
    }
    sort(print, print+cnt);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) cout << print[i] << endl;
}