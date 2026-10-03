#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int digit[10][7] = {{1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0},
                    {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1},
                    {0, 1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 1, 1},
                    {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0},
                    {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

int main() {
    FASTIO

    int s;
    string num;

    cin >> s >> num;

    int num_size = num.size();

    for(int i = 0; i < num_size; i++) {
        int number = num[i]-'0';

        cout << " ";
        if(digit[number][0] == 1) {
            for(int k = 0; k < s; k++) cout << "-";
        }
        else {
            for(int k = 0; k < s; k++) cout << " ";
        }
        cout << " ";
        cout << " ";
    }
    cout << "\n";

    for(int _ = 0; _ < s; _++) {
        for(int i = 0; i < num_size; i++) {
            int number = num[i]-'0';

            if(digit[number][1] == 1) cout << "|";
            else cout << " ";
            for(int k = 0; k < s; k++) cout << " ";
            if(digit[number][2] == 1) cout << "|";
            else cout << " ";
            cout << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < num_size; i++) {
        int number = num[i]-'0';

        cout << " ";
        if(digit[number][3] == 1) {
            for(int k = 0; k < s; k++) cout << "-";
        }
        else {
            for(int k = 0; k < s; k++) cout << " ";
        }
        cout << " ";
        cout << " ";
    }
    cout << "\n";

    for(int _ = 0; _ < s; _++) {
        for(int i = 0; i < num_size; i++) {
            int number = num[i]-'0';

            if(digit[number][4] == 1) cout << "|";
            else cout << " ";
            for(int k = 0; k < s; k++) cout << " ";
            if(digit[number][5] == 1) cout << "|";
            else cout << " ";
            cout << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < num_size; i++) {
        int number = num[i]-'0';

        cout << " ";
        if(digit[number][6] == 1) {
            for(int k = 0; k < s; k++) cout << "-";
        }
        else {
            for(int k = 0; k < s; k++) cout << " ";
        }
        cout << " ";
        cout << " ";
    }
    cout << "\n";
}