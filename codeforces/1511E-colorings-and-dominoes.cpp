#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint998244353;

int solve(vector<string> s)
{
    int          n = s.size(), m = s.back().size();
    int const    NMAX = 3e5 + 11;
    vector<mint> p(NMAX);
    p[0] = mint(1) / 2;
    for (int i = 1; i < NMAX; ++i)
    {
        if (i % 2)
            p[i] = p[i - 1] - mint(1) / mint(2).pow(i);
        else
            p[i] = p[i - 1] + mint(1) / mint(2).pow(i);
    }

    mint ans = 0;
    int  w   = 0;
    for (int i = 0; i < n; ++i)
        w += count(all(s[i]), 'o');

    for (int i = 0; i < n; ++i)
    {
        int c = 0;
        for (int j = 0; j < m; ++j)
        {
            if (s[i][j] == '*')
                c = 0;
            else
                c++;
            if (c > 0)
                ans += p[c];
        }
    }
    for (int j = 0; j < m; ++j)
    {
        int c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i][j] == '*')
                c = 0;
            else
                c++;
            if (c > 0)
                ans += p[c];
        }
    }
    return (ans * mint(2).pow(w)).val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    read(all(s));

    cout << solve(s) << endl;

    return 0;
}
