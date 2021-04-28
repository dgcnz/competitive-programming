#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/binary_exponentiation>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace std::placeholders;
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using pll = pair<ll, ll>;

ll solve(vector<pll> creatures, int a, int b)
{
    auto f   = [](pll x) { return x.first - x.second; };
    auto cmp = [f](pll x, pll y) { return f(x) < f(y); };

    sort(all(creatures), cmp);
    reverse(all(creatures));
    ll  total = 0;
    int last = 0, n = creatures.size();
    for (auto [hp, dmg] : creatures)
    {
        if (last < b and hp > dmg)
            dmg = hp, last++;
        total += dmg;
    }

    ll k = 1LL << a, ans = total;
    for (int i = 0; i < n; ++i)
    {
        auto [hp, dmg] = creatures[i];
        int rem        = b - last;
        if (rem > 0 and i >= last)
            ans = max(ans, total - dmg + hp * k);
        else if (rem > 0 and i < last)
            ans = max(ans, total - hp + hp * k);
        else if (rem == 0 and b and i >= last)
            ans = max(ans,
                      total - creatures[last - 1].first +
                          creatures[last - 1].second + -dmg + hp * k);
        else if (rem == 0 and b and i < last)
            ans = max(ans, total - hp + hp * k);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    vector<pll> creatures(n);
    for (auto &[hp, dmg] : creatures)
        cin >> hp >> dmg;
    cout << solve(creatures, a, b) << endl;
    return 0;
}
