#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t;
    string func, str;
    deque<int> dq;

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        while(!dq.empty()) dq.pop_front();
        int sw = 0, cnt = 0, k = 0;
        cin >> func >> n;
        cin >> str;
        while(str[k] != '\0') {
			int num = 0;
			while(str[k] >= '0' && str[k] <= '9') {
				num *= 10;
				num += int(str[k++] - '0');
			}
			if(num != 0) dq.push_back(num);
			k++;
        }
        for(int i = 0; i < func.size(); i++) {
            if(func[i] == 'D') cnt++;
        }
        if(n < cnt) {
            cout << "error\n";
            continue;
        }
        for(int i = 0; i < func.size(); i++) {
            if(func[i] == 'R') sw = 1-sw;
            else if(func[i] == 'D' && sw == 0) dq.pop_front();
            else if(func[i] == 'D' && sw == 1) dq.pop_back();
        }
        cout << '[';
        int len = dq.size();
        for(int i = 0; i < len; i++) {
            if(sw == 0) {
                cout << dq.front();
                dq.pop_front();
                if(i != len-1) cout << ',';
            }
            else if(sw == 1) {
                cout << dq.back();
                dq.pop_back();
                if(i != len-1) cout << ',';
            }
        }
        cout << "]\n";
    }
}