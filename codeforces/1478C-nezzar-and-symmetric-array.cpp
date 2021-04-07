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

bool solve(vector<ll> d)
{
    int        n   = d.size() / 2;
    ll         sum = 0;
    vector<ll> a(n);
    sort(all(d), greater<ll>());
    for (int i = 0; i < n; ++i)
    {
        int j = i << 1;
        if (d[j] != d[j + 1])
            return false;
        ll nom = d[j] - 2 * sum, denom = 2 * (n - i);
        if (nom % denom != 0)
            return false;
        a[i] = nom / denom;
        if (a[i] <= 0 or (i > 0 and a[i] == a[i - 1]))
            return false;
        sum += a[i];
    }
    dbg(a);
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> d(2 * n);
        read(all(d));
        cout << (solve(d) ? "Yes" : "No") << endl;
    }
    return 0;
}
