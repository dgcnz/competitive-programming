#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> a)
{
    int          n = a.size();
    map<ll, int> last;

    last[0] = -1;
    ll  sum = 0, ans = 0;
    int invalid_ix = -1;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        if (last.contains(sum))
            invalid_ix = max(last[sum] + 1, invalid_ix);
        last[sum] = i;
        ans += i - invalid_ix;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);
    read(all(a));

    cout << solve(a) << endl;
    return 0;
}
