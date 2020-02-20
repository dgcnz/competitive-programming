#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

bool solve(ll *coins, ll n) {
  sort(coins, coins + 3);

  ll res = n - ((coins[2] - coins[1]) + (coins[2] - coins[0]));
  ll sum = accumulate(coins, coins + 3, 0);

  if ((res < 0) or (res % 3 != 0)) {
    return false;
  }

  if (((sum + n) % 3 != 0) or ((3 * coins[2] + res) != (sum + n))) {
    return false;
  }

  return true;
}

int main(void) {

  int t;
  cin >> t;

  while (t--) {
    ll coins[3], n;
    cin >> coins[0] >> coins[1] >> coins[2] >> n;

    if (solve(coins, n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
