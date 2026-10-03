#include <iostream>
#include <string>
using namespace std;

#define MAX 555555
#define lli long long int

lli n, failure[MAX] = {-1, };
string str;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;
    cin >> n;

    lli str_size = str.size();

    for(lli i = 1; i < str_size; i++) {
        lli j = failure[i-1];

        while(str[i] != str[j+1] && j >= 0) j = failure[j];

        if(str[i] == str[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    cout << str_size*n - (n-1)*(failure[str_size-1]+1);
}