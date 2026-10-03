#include <iostream>
#include <queue>
using namespace std;

int t, n;
long int temp;

priority_queue<long int> minq;
priority_queue<long int> maxq;

int main() {
    // cin.tie(NULL); cout.tie(NULL);
    // ios::sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        cout << n/2+1 << "\n";
        for(int i = 0; i < n; i++) {
            cin >> temp;

            int minq_size = minq.size();
            int maxq_size = maxq.size();
            
            if(minq_size == 0) minq.push(temp);
            else if(maxq_size == 0) maxq.push(-temp);
            else if(minq_size == maxq_size) minq.push(temp);
            else maxq.push(-temp);

            if(i > 0 && minq.top() > -maxq.top()) {
                long int a = minq.top();
                long int b = -maxq.top();

                minq.pop();
                maxq.pop();
                
                minq.push(b);
                maxq.push(-a);
            }

            if(i%2 == 0) cout << minq.top() << " ";
            else if(i%20 == 19) cout << "\n";
        }
        cout << "\n";

        while(minq.size()) minq.pop();
        while(maxq.size()) maxq.pop();
    }

    return 0;
}