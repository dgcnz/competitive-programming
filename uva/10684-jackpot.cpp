// dp(i): maximum streak ending at i (having chosen i)
// dp(i) = max(v(i) + dp(i-1), v(i))

#include <algorithm>
#include <iostream>

#define NMAX 10010

using namespace std;

int N;
int dp[NMAX];
int v[NMAX];

int solve(void) {

  // Calcualating dp
  dp[0] = max(v[0], 0);

  for (int i = 1; i < N; ++i)
    dp[i] = max(v[i] + dp[i - 1], v[i]);

  return *max_element(dp, dp + N);
}

int main(void) {

  while (cin >> N and N != 0) {
    for (int i = 0; i < N; ++i)
      cin >> v[i];
    int ans = solve();
    if (ans > 0)
      cout << "The maximum winning streak is " << ans << ".\n";
    else
      cout << "Losing streak.\n";
  }

  return 0;
}
