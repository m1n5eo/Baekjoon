#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> solution() {
    int n;
    cin >> n;
    vector<int> number;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        number.push_back(0);
        number.push_back(temp);
    }
    number.push_back(0);

    int p, r = -1; n = number.size();
    vector<int> manacher(n, 0);
    for(int i = 0; i < n; i++) {
        if(i > r) {
            p = r = i;
            while(r < n && r <= 2*p && number[r] == number[2*p-r]) r += 1;
            r -= 1;
            manacher[i] = r-p;
        }
        else {
            int j = 2*p-i;
            if(manacher[j] < r-i) manacher[i] = manacher[j];
            else if(manacher[j] > r-i) manacher[i] = r-i;
            else {
                p = i;
                while(r < n && r <= 2*p && number[r] == number[2*p-r]) r += 1;
                r -= 1;
                manacher[i] = r-p;
            }
        }
    }

    int m;
    cin >> m;
    vector<int> result;
    for(int _ = 0; _ < m; _++) {
        int a, b; cin >> a >> b;
        a = a*2-1, b = b*2-1;
        int mid = (a+b)/2;
        if(mid + manacher[mid] - 1 >= b) result.push_back(1);
        else result.push_back(0);
    }
    return result;
}

int main() {
    FASTIO
    for(int sol : solution()) cout << sol << "\n";
}