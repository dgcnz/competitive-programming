#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
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

int const NMAX = 1e6 + 11;
vi        presents[NMAX], wishers[NMAX];

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int ki;
        cin >> ki;
        for (int j = 0; j < ki; ++j)
        {
            int aj;
            cin >> aj, aj--;
            presents[i].push_back(aj);
            wishers[aj].push_back(i);
        }
        m = max(ki, m);
    }

    mint ans = 0;
    for (int x = 0; x < n; ++x)
    {
        mint cur = 0;
        for (auto y : presents[x])
            cur += wishers[y].size();
        cur /= presents[x].size();
        ans += cur;
    }
    ans /= mint(n).pow(2);
    cout << ans.val() << endl;

    return 0;
}
