long int findNextSquare(long int sq) {
  for(long int i = 0; ; i++) {
    if(i*i < sq) continue;
    else if(i*i == sq) return (i+1)*(i+1);
    else return -1;
  }
}