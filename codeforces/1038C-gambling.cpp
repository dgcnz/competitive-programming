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

ll solve(vi a, vi b)
{
    int n = a.size();
    a.push_back(0);
    b.push_back(0);
    sort(all(a));
    sort(all(b));
    ll ans = 0;
    for (int turn = 0; turn < n; ++turn)
    {
        if (a.back() >= b.back())
        {
            ans += a.back();
            a.pop_back();
        }
        else
            b.pop_back();

        if (b.back() >= a.back())
        {
            ans -= b.back();
            b.pop_back();
        }
        else
            a.pop_back();
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);
    read(all(a));
    read(all(b));

    cout << solve(a, b) << endl;
    return 0;
}
