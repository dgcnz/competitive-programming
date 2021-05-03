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
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

ll solve(vector<ii> ab)
{
    int const                NMAX = 3e5 + 11, n = ab.size();
    vector<ii>               ba(n);
    Combinations<NMAX, mint> C;
    mint                     ans = C.factorial(n);

    for (int k = 0; k < 2; ++k)
    {
        sort(all(ab));
        mint cur = 1;
        int  i   = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n and ab[j].first == ab[i].first)
                ++j;
            cur *= C.factorial(j - i);
            i = j;
        }
        ans -= cur;
        transform(all(ab), begin(ab), [](ii x) {
            return ii{x.second, x.first};
        });
    }
    sort(all(ab));
    if (is_sorted(all(ab), [](ii x, ii y) { return x.second < y.second; }))
    {
        mint cur = 1;
        int  i   = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n and ab[j].first == ab[i].first)
                ++j;
            map<int, int> cnt;
            for (int k = i; k < j; ++k)
                ++cnt[ab[k].second];
            for (auto [ai, c] : cnt)
                cur *= C.factorial(c);
            i = j;
        }
        ans += cur;
    }

    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> ab(n);
    for (auto &[a, b] : ab)
        cin >> a >> b;
    cout << solve(ab) << endl;
    return 0;
}
