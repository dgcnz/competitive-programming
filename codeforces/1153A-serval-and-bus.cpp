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
    int n, t;
    cin >> n >> t;

    int const INF = 2e9;
    ii        ans = {INF, -1};
    for (int i = 1; i <= n; ++i)
    {
        int s, d;
        cin >> s >> d;

        int cur = s >= t ? s : s + d * ((t - s + d - 1) / d);
        ans     = min(ans, {cur, i});
    }
    cout << ans.second << endl;
    return 0;
}
