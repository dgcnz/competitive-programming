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

vi solve(ll k)
{
    if (k % 2)
        return {};

    vector<ll> Ex = {0};
    while (2 * (Ex.back() + 1) <= k)
        Ex.push_back(2 * (Ex.back() + 1));

    vi ans;
    while (k)
    {
        int m = distance(Ex.begin(), upper_bound(all(Ex), k)) - 1;
        ans.push_back(1);
        ans.resize(ans.size() + m - 1, 0);
        k -= Ex[m];
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
        ll k;
        cin >> k;
        if (auto ans = solve(k); ans.size())
        {
            cout << ans.size() << endl;
            write(all(ans), " "), cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
