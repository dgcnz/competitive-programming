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

ll iceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);
    read(all(a));

    map<ll, int> cnt;
    for (auto ai : a)
        cnt[ai]++;

    int  ans = 0, mx = cnt.rbegin()->first;
    bool flag = true;
    while (not cnt.empty())
    {
        auto it     = cnt.begin();
        auto [x, m] = *it;
        if (cnt.size() == 1 and m == 1)
            break;
        if (2 * x > mx and cnt.size() > 1)
        {
            flag = false;
            break;
        }
        if (m % 2)
            ans++;
        cnt[2 * x] += iceil(m, 2);
        cnt.erase(it);
    }
    if (flag)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}
