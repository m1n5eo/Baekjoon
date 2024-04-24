#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t, year, month, day, birthday;
    int max_birthday = -1234567890, min_birthday = 1234567890;
    string name, max_name, min_name;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> name >> day >> month >> year;

        birthday = year*10000 + month*100 + day;

        if(birthday > max_birthday) {
            max_birthday = birthday;
            max_name = name;
        }
        if(birthday < min_birthday) {
            min_birthday = birthday;
            min_name = name;
        }
    }

    cout << max_name << "\n" << min_name;

    return 0;
}