#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int len;
  while(cin >> len){
      int seq[3002],  delta[3002], hits = 0;
      for(int i = 0; i < len; i++){
          cin >> seq[i];
      }
      for(int i = 0; i < len - 1; i++){
          delta[i] = abs(seq[i + 1] - seq[i]);
      }
      sort(delta, delta+len-1);
      for(int i = 0; i < len - 1; i++){
          if(delta[i] != delta[i + 1]) hits++;
      }
      if(hits == len - 1) printf("Jolly\n");
      else printf("Not jolly\n");
  }
  return 0;
}