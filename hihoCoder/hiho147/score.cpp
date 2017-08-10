#include <bitset>
#include <cstdio>
const int N = 30001;
int r[5][N];
int rev[5][N];
std::bitset<N> b[5][N];
int main() {
  int n;
  scanf("%d", &n);
  int t[5];
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d %d", &t[0], &t[1], &t[2], &t[3], &t[4]);
    for (int j = 0; j < 5; ++j) {
      r[j][i] = t[j];
      rev[j][t[j]] = i;
    }
  }
  for (int i = 2; i <= n; ++i)
    for (int j = 0; j < 5; ++j) {
      b[j][i] |= b[j][i - 1];
      b[j][i].set(rev[j][i - 1]);
    }
  for (int k = 1; k <= n; ++k)
    printf("%ld\n",
           (b[0][r[0][k]] & b[1][r[1][k]] & b[2][r[2][k]] & b[3][r[3][k]] &
            b[4][r[4][k]])
               .count());
  return 0;
}
