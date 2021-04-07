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
using ii = pair<ll, ll>;
using vi = vector<int>;

ll solve(ll b, ll c)
{
    ii left  = {-b - (c - 1) / 2, -b + (c - 1) / 2},
       right = {b - c / 2, b + (c - 2) / 2};

    auto count = [](ii lr) { return lr.second - lr.first + 1; };
    if (left.second >= right.first)
        return count(
            {min(left.first, right.first), max(left.second, right.second)});
    else
        return count(left) + count(right);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll b, c;
    cin >> b >> c;
    cout << solve(b, c) << endl;
    return 0;
}
