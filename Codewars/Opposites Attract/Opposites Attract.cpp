bool lovefunc(int f1, int f2) {
  if((f1%2 == 0 and f2%2 == 1) or (f1%2 == 1 and f2%2== 0)) return true;
  else return false;
}