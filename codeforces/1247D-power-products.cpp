#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/sieve>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const   NMAX = 1e5 + 11;
Sieve<NMAX> sieve;

ll solve(vi a, int k)
{
    map<vector<ii>, int> cnt;
    ll                   ans = 0;
    for (auto ai : a)
    {
        vector<ii> h, h2;
        for (ll p : sieve.primes)
        {
            if (p > ai)
                break;
            int e = 0;
            while (ai % p == 0)
                e++, ai /= p;
            if (e % k == 0)
                continue;
            h.emplace_back(p, e % k);
            h2.emplace_back(p, k - (e % k));
        }

        ans += cnt[h2];
        cnt[h]++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n);
    read(all(a));
    cout << solve(a, k) << endl;
    return 0;
}
