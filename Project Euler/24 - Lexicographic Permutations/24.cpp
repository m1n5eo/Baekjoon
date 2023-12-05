#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NUMBER 1000000

int main() {
    vector<int> num, temp;
    queue<int> cnt, res;
    int n = NUMBER-1, arr[11] = {0, };
    num.push_back(0);
    for(int i = 1, gop = 1; i < 10; i++, gop*=i) {
        arr[i] = gop;
        num.push_back(i);
    }

    for(int i = 9; i >= 0; i--) {
        if(n == 0) cnt.push(0);
        else {
            cnt.push(n/arr[i]);
            n -= n/arr[i]*arr[i];
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 9-cnt.front()-i; j++) {
            temp.push_back(num.back());
            num.pop_back();
        }
        res.push(num.back());
        num.pop_back();
        for(int j = 0; j < 9-cnt.front()-i; j++) {
            num.push_back(temp.back());
            temp.pop_back();
        }
        cnt.pop();
    }

    for(int i = 0; i < 10; i++) {
        cout << res.front();
        res.pop();
    }
}