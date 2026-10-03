#include <iostream>
using namespace std;

string str[3];
int idx, number, result;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i < 3; i++) {
        cin >> str[i];

        if(str[i][0] != 'F' && str[i][0] != 'B') {
            idx = i;
            number = stoi(str[i]);
        }
    }

    result = number+(3-idx);

    if(result%3 == 0 && result%5 == 0) cout << "FizzBuzz";
    else if(result%3 == 0) cout << "Fizz";
    else if(result%5 == 0) cout << "Buzz";
    else cout << result;
}