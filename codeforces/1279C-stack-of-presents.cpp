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

ll solve(vi a, vi b)
{
    int n = a.size(), m = b.size();
    vi  pos(n);
    for (int i = 0; i < n; ++i)
        pos[a[i]] = i;

    int j = 0, removed = 0;
    ll  ans = 0;
    while (j < m)
    {
        ans += 2 * (pos[b[j]] - removed) + 1;
        removed++;
        int k = j + 1;
        while (k < m and pos[b[k]] < pos[b[j]])
            k++, ans++, removed++;
        j = k;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        read(all(a));
        read(all(b));

        transform(all(a), begin(a), [](int x) { return x - 1; });
        transform(all(b), begin(b), [](int x) { return x - 1; });

        cout << solve(a, b) << endl;
    }
    return 0;
}
