#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const KMAX = 1e6 + 11;
int       cnt[KMAX];

int solve(vi a, int k, int d)
{
    set<int> window;
    for (int i = 0; i < d; ++i)
        window.insert(a[i]), cnt[a[i]]++;

    int ans = window.size(), n = a.size();
    for (int i = d; i < n; ++i)
    {
        int l = a[i - d], r = a[i];
        cnt[l]--, cnt[r]++;
        if (cnt[l] == 0)
            window.erase(l);
        if (cnt[r] == 1)
            window.insert(r);
        ans = min(ans, (int)window.size());
    }
    for (int i = n - d; i < n; i++)
        cnt[a[i]]--;
    (void)k;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, d;
        cin >> n >> k >> d;

        vi a(n);
        read(all(a));
        transform(all(a), begin(a), [](int ai) { return ai - 1; });
        cout << solve(a, k, d) << "\n";
    }
    return 0;
}
