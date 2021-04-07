#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> c)
{
    int n = c.size();

    ll           ans = c[0] * n + c[1] * n, cur = ans;
    array<ll, 2> minv   = {c[0], c[1]};
    array<ll, 2> length = {n, n};

    for (int i = 2; i < n; ++i)
    {
        length[i % 2] -= 1;
        if (minv[i % 2] > c[i])
        {
            cur -= length[i % 2] * minv[i % 2];
            cur += length[i % 2] * c[i];
            minv[i % 2] = c[i];
        }
        else
        {
            cur -= minv[i % 2];
            cur += c[i];
        }
        ans = min(ans, cur);
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
        int n;
        cin >> n;
        vector<ll> c(n);
        for (auto &ci : c)
            cin >> ci;
        cout << solve(c) << endl;
    }
    return 0;
}
