#include <vector>
using namespace std;

vector<int> invert(vector<int> values) {
  for(int i = 0; i < values.size(); i++) values[i] = -values[i];
  return values;
}