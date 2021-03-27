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

int solve(int n, vector<tuple<int, int, bool>> testimonies)
{
    int  ans    = 0;
    auto honest = [](int mask, int i) { return bool(mask & (1 << i)); };
    auto check  = [&](int mask) {
        for (auto [u, v, b] : testimonies)
            if (honest(mask, u) and b != honest(mask, v))
                return false;
        return true;
    };
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int cnt = __builtin_popcount(mask);
        if (ans < cnt and check(mask))
            ans = cnt;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<tuple<int, int, bool>> testimonies;
    for (int u = 0; u < n; ++u)
    {
        int a;
        cin >> a;
        while (a--)
        {
            int  v;
            bool b;
            cin >> v >> b, v--;
            testimonies.emplace_back(u, v, b);
        }
    }
    cout << solve(n, testimonies) << endl;
    return 0;
}
