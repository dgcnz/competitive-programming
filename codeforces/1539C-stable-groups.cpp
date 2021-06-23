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

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int solve(vector<ll> a, ll k, ll x)
{
    sort(all(a));
    vector<ll> needed;

    ll pai = a.front();
    for (auto ai : a)
    {
        if (ai - pai > x)
            needed.push_back(ceil((ai - pai), x) - 1);
        pai = ai;
    }
    int ans = needed.size() + 1;
    sort(all(needed));
    for (auto d : needed)
    {
        if (d > k)
            break;
        k -= d;
        ans--;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  k, x;

    cin >> n >> k >> x;
    vector<ll> a(n);
    read(all(a));

    cout << solve(a, k, x) << endl;

    return 0;
}
