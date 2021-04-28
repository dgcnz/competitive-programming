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

struct kadane
{
    vector<ll> a;
    ll         ans;
    int        l, r;
    kadane(vector<ll> a) : a(a) {}

    ll solve()
    {
        ll  cur_max = 0;
        int s = 0, n = a.size();
        l = 0, r = 0;
        ans = LONG_LONG_MIN;

        for (int i = 0; i < n; i++)
        {
            cur_max += a[i];

            if (ans < cur_max)
            {
                ans = cur_max;
                l   = s;
                r   = i;
            }

            if (cur_max < 0)
            {
                cur_max = 0;
                s       = i + 1;
            }
        }
        r++;
        return ans;
    }
    ll             answer() const { return ans; }
    pair<int, int> indices() const { return {l, r}; }
};

ll solve(vector<ll> a, int x)
{
    int        n = a.size();
    vector<ll> pa(n);
    partial_sum(all(a), begin(pa));

    vector<ll> left(n);
    left[0] = max(0LL, a[0]);
    for (int r = 1; r < n; ++r)
        left[r] = max({0LL, left[r - 1] + a[r], a[r]});

    vector<ll> right(n);
    right[n - 1] = max(0LL, a[n - 1]);
    for (int l = n - 2; l >= 0; --l)
        right[l] = max({0LL, right[l + 1] + a[l], a[l]});

    ll ans = 0, best = 0;
    for (int r = 0; r < n; ++r)
    {
        ans  = max(ans, (r < n - 1 ? right[r + 1] : 0) + x * pa[r] + best);
        ans  = max(ans, left[r]);
        best = max(best, left[r] - x * pa[r]);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    read(all(a));

    cout << solve(a, x) << endl;

    return 0;
}
