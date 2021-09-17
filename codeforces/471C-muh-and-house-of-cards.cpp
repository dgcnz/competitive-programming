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

ll sq(ll x) { return (x * (x + 1)) / 2; }

int solve(ll n)
{
    int l = 1, ans = 0;
    while ((n + l) / 3 >= sq(l))
    {
        if ((n + l) % 3 == 0)
            ans++;
        l++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
