#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, phone[22];
    int YoungSik = 0, MinSik = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> phone[i];

        YoungSik += (phone[i]/30+1)*10;
        MinSik += (phone[i]/60+1)*15;
    }

    if(YoungSik < MinSik) {
        cout << "Y " << YoungSik;
    }
    else if(YoungSik == MinSik) {
        cout << "Y M " << YoungSik;
    }
    else if(YoungSik > MinSik) {
        cout << "M " << MinSik;
    }

    return 0;
}