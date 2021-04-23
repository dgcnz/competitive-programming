#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vi a(n);
    read(all(a));
    transform(all(a), a.begin(), [](int ai) { return ai - 1; });

    vector<vi> pos(n);
    for (int i = 0; i < n; ++i)
        pos[a[i]].push_back(i);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (q--)
    {
        int l, r;
        cin >> l >> r, l--, r--;
        int ans = 1;
        for (int _ = 0; _ < 40; _++)
        {
            int x   = a[uniform_int_distribution<int>(l, r)(rng)];
            int cnt = upper_bound(pos[x].begin(), pos[x].end(), r) -
                      lower_bound(pos[x].begin(), pos[x].end(), l);
            ans = max(ans, 2 * cnt - (r - l + 1));
        }
        cout << ans << endl;
    }

    return 0;
}
