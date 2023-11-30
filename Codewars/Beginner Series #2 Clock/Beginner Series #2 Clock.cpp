int past(int h, int m, int s) {
  int ans = h*3600 + m*60 + s;
  return ans*1000;
}