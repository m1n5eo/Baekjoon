#include <vector>
using namespace std;

vector<int> digitize(unsigned long n) {
  vector<int> ans;
  do {
    ans.push_back(n%10);
    n = n/10;
  } while(n);
  return ans;
}