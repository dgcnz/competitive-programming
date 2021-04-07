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

int bs(int l, int r, function<bool(int)> p)
{
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;

    auto ok = [n](int x) {
        ll pten = 1, tmp = x;
        while (tmp)
            pten *= 10, tmp /= 10;
        ll y = x + pten * x;
        return y <= n;
    };
    int i = bs(0, sqrt(n) + 100, ok);
    cout << i << endl;

    return 0;
}
