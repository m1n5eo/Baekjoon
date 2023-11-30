#include <vector>
using namespace std;

float find_uniq(const vector<float> &v) {
  for(int i = 1; i < v.size()-1; i++) {
    if(v[i-1] != v[i] && v[i] != v[i+1] && v[i-1] == v[i+1]) {
      return v[i];
    }
  }
  if(v[0] != v[1] && v[0] != v[2] && v[1] == v[2]) return v[0];
  else return v[v.size()-1];
}