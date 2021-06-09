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

vector<ll> solve(vector<ll> a)
{
    int               n = a.size();
    map<ll, set<int>> pos;
    auto              cmp = [&](ll x, ll y) {
        auto &px = pos[x];
        auto &py = pos[y];
        if (px.size() >= 2 and py.size() >= 2)
            return x < y;
        return px.size() > py.size();
    };
    set<ll, decltype(cmp)> ord(cmp);
    for (int i = 0; i < n; ++i)
        pos[a[i]].insert(i);
    for (int i = 0; i < n; ++i)
        ord.insert(a[i]);

    int cnt = n;
    while (cnt--)
    {
        auto  itx = ord.begin();
        ll    x   = *itx;
        auto &px  = pos[x];
        if (px.size() < 2)
            break;
        a[*px.begin()] = -1;
        px.erase(px.begin());
        int i = *px.begin();
        px.erase(px.begin());
        ord.erase(itx);
        ord.insert(x);

        ll y     = 2 * x;
        a[i]     = y;
        auto ity = ord.find(y);
        pos[y].insert(i);
        if (ity == ord.end())
            ord.insert(y);
        else
        {
            ord.erase(ity);
            ord.insert(y);
        }
    }
    vector<ll> ans;
    for (auto ai : a)
        if (ai != -1)
            ans.push_back(ai);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    auto ans = solve(a);
    cout << ans.size() << endl;
    write(all(ans), " "), cout << endl;
    return 0;
}
