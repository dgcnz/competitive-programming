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

int solve(ll n)
{
    int  ans      = 0;
    bool all_nine = true;
    while (n >= 10)
    {
        if (n % 10 != 9)
            all_nine = false;
        ans += 9;
        n /= 10;
    }
    return ans + (all_nine ? n : n - 1);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}
