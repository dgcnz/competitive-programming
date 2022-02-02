#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint1000000007;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    atcoder::dsu dsu(m + 1);
    vector<int>  ans;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;

        int a, b = m;
        cin >> a, a--;
        if (k == 2)
            cin >> b, b--;

        if (not dsu.same(a, b))
        {
            dsu.merge(a, b);
            ans.push_back(i);
        }
    }

    mint tsz = mint(2).pow(ans.size());

    cout << tsz.val() << " " << ans.size() << endl;

    increment(all(ans));
    write(all(ans), " "), cout << endl;

    return 0;
}
