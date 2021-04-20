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

bool solve(vector<ll> a)
{
    sort(all(a));
    int           n   = a.size();
    ll            rem = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        cnt[a[i]]++;
        rem += a[i] - i;
    }
    bool cnt_two = false;
    for (auto [x, c] : cnt)
    {
        if (c > 1)
        {
            if (c > 2)
                return 0;
            if (cnt_two)
                return 0;
            if (x == 0)
                return 0;
            if (cnt[x - 1] > 0)
                return 0;
            cnt_two = true;
        }
    }
    return rem % 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll>     a(n);
    vector<string> ans = {"cslnb", "sjfnb"};
    read(all(a));
    cout << ans[solve(a)] << endl;
    return 0;
}
