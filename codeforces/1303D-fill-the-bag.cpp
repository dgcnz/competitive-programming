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

ll solve(ll n, vector<ll> a)
{
    vector<int> cnt(64, 0);
    ll          sum = 0;
    for (auto ai : a)
    {
        cnt[63 - __builtin_clzll(ai)]++;
        sum += ai;
    }
    if (sum < n)
        return -1;

    ll ans = 0;
    for (int i = 0; i < 64; ++i)
    {
        if (n & (1LL << i))
        {
            if (cnt[i])
            {
                cnt[i]--;
                cnt[i + 1] += cnt[i] / 2;
            }
            else
            {
                int j = i;
                while (j < 64 and cnt[j] == 0)
                    j++;
                if (j == 65)
                    return -1;
                while (j > i)
                {
                    cnt[j]--;
                    cnt[j - 1] += 2;
                    --j;
                    ans++;
                }
            }
        }
        else if (cnt[i])
            cnt[i + 1] += cnt[i] / 2;
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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(m);
        read(all(a));
        cout << solve(n, a) << endl;
    }
    return 0;
}
