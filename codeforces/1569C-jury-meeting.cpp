#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/combinatorics>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using mint                    = modint998244353;
int const                NMAX = 2e5 + 11;
Combinations<NMAX, mint> Comb;

int solve(vi a)
{
    int n       = a.size();
    int largest = *max_element(all(a));
    int k       = n - 1 - count(all(a), largest - 1);

    mint ans = Comb.factorial(n);

    if (count(all(a), largest) > 1)
        return ans.val();
    else if (k == n - 1)
        return 0;

    for (int i = 0; i <= k; ++i)
    {
        auto x = Comb.C(k, i) * Comb.factorial(i) * Comb.factorial(n - 1 - i);
        ans -= x;
    }
    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        read(all(a));

        cout << solve(a) << endl;
    }
    return 0;
}
