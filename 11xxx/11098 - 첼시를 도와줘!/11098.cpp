#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int n, price, max_price = 0;
        string name, max_name;

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> price >> name;

            if(price > max_price) {
                max_price = price;
                max_name = name;
            }
        }

        cout << max_name << "\n";
    }

    return 0;
}