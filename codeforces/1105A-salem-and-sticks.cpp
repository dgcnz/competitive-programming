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

    int const INF = 1e6;
    ii        ans = {INF, INF};

    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    for (int t = 1; t <= 100; ++t)
    {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += min({abs(a[i] - t), abs(a[i] - t + 1), abs(a[i] - t - 1)});
        ans = min(ans, ii{cur, t});
    }
    cout << ans.second << " " << ans.first << endl;
    return 0;
}
