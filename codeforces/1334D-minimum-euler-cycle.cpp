#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool intersect(ll l1, ll r1, ll l2, ll r2) { return min(r1, r2) > max(l1, l2); }

vi solve(ll n, ll l, ll r)
{
    if (l == r and l == n * (n - 1) + 1)
        return {1};
    vi ans;
    ll id = 0;
    l--;

    function<void(ll, ll, ll &)> f = [&](ll lf, ll rg, ll &id)
    {
        if (lf == rg)
            return;

        if (intersect(l, r, id, id + 2 * (rg - lf)))
        {
            for (int to = lf + 1; to < rg + 1; ++to)
            {
                if (l <= id && id < r)
                    ans.push_back(lf);
                id++;

                if (l <= id && id < r)
                    ans.push_back(to);
                id++;
            }
        }
        else
            id += 2 * (rg - lf);

        f(lf + 1, rg, id);

        if (lf == 0)
        {
            if (l <= id && id < r)
                ans.push_back(lf);
            id++;
        }
    };

    f(0, n - 1, id);
    increment(all(ans));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        auto ans = solve(n, l, r);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
