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

int solve(vector<ll> neg, vector<ll> pos, ll t)
{
    auto f = [&pos](ll t) {
        auto it = upper_bound(all(pos), t);
        return distance(pos.begin(), it);
    };

    int ans = f(t);
    for (int i = 0, n = neg.size(); i < n; ++i)
    {
        ll ct = t - 2 * neg[i];
        if (ct < 0)
            break;

        ans = max(ans, i + 1 + (int)f(ct));
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<ll> pos, neg;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x >= 0)
            pos.push_back(x);
        else
            neg.push_back(-x);
    }
    reverse(all(neg));

    auto ans = max(solve(neg, pos, t), solve(pos, neg, t));
    cout << ans << endl;
    return 0;
}
