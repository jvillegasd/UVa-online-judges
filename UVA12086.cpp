#include <stdio.h>
#include <string.h>

using namespace std;

int pots[900000];
//Segmend tree implemetation
void insert_update(int idx, int st, int ed, int pos, int value)
{
    if(st == pos && pos == ed)
    {
        pots[idx] = value;
        return;
    }
 
    int l = idx * 2;
    int r = l + 1;
    int mid = (st + ed) / 2;
 
    if(pos <= mid) insert_update(l, st, mid, pos, value);
    else insert_update(r, mid+1, ed, pos, value);
 
    pots[idx] = pots[l] + pots[r];
}
 
 
int quer(int idx, int st, int ed, int i, int j)
{
    if(i==st && j==ed) return pots[idx];
 
    int l = idx * 2;
    int r = l + 1;
    int mid = (st + ed) / 2;
 
 
    if(j<=mid)
    {
        return quer(l, st, mid, i, j);
    }
    else if(i > mid)
    {
        return quer(r, mid+1, ed, i, j);
    }
    else return quer(l, st, mid, i, mid) + quer(r, mid+1, ed, mid+1, j);
 
 
}

int main()
{
  int n, tc = 0, x, y, num;
  char type[4];
  while (scanf("%d", &n), n)
  {
      for (int i = 1; i <= n; i++){
        scanf("%d", &num);
        insert_update(1, 1, n, i, num);
      }
      if(tc) printf("\n");
      printf("Case %d:\n", ++tc);
      while (scanf("%s", type), strcmp(type, "END") !=0)
      {
        scanf("%d %d", &x, &y);
        if (type[0] == 'S')
        { 
          insert_update(1, 1, n, x, y);
        } else if (type[0] == 'M'){
            int sum = quer(1, 1, n, x, y);
            printf("%d\n", sum);
          }
        } 
      } 
  return 0;
}