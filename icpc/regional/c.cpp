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

ll solve(vector<int> a)
{
    int n   = a.size();
    ll  sum = accumulate(all(a), 0LL);
    int k   = sum / n;
    ll  ans = 0;
    for (int d = 0; d < 2 * n; ++d)
    {
        int i = d % n;
        int j = (d + 1) % n;

        if (a[i] < k)
            continue;
        ans += a[i] - k;
        a[j] += (a[i] - k);
        a[i] = k;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    ll ans = min(solve(a), solve(vi(rbegin(a), rend(a))));
    cout << ans << endl;
    return 0;
}
