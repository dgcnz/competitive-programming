// STATUS: ACCEPTED
#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

ll solve(ll A, ll B) {
  ll count = 0;

  ll maxdig = log10(B) + 1;
  count = maxdig - 1;
  if (B == (ll)pow(10, maxdig) - 1)
    ++count;

  return A * count;
}

int main(void) {

  ll t;

  cin >> t;
  while (t--) {
    ll A, B;
    cin >> A >> B;
    ll n = solve(A, B);
    cout << n << endl;
  }
  return 0;
}
