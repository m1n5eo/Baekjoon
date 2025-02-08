#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    int n, temp;
	vector<int> student;
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		student.push_back(temp);
	}

    for(int i = 0; i <= student[0]; i++) {
        int a = i;
        int d = student[0] - a;
        int e = student[5] - d;
        int b = student[2] - e;
        int c = student[1] - b;
        int f = student[4] - c;

        if(a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && f >= 0) {
			cout << 1 << "\n";
			cout << a << " " << d << "\n";
			cout << b << " " << e << "\n";
			cout << c << " " << f << "\n";

            return 0;
        }
    }
	
	cout << 0 << "\n";
}