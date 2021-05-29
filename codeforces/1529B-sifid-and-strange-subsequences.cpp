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

int solve(vector<ll> a)
{
    int n = a.size();

    sort(all(a));
    if (a[0] > 0 or a.size() == 1)
        return 1;
    if (a[1] > 0)
        return 2;

    ll minv = abs(a[0] - a[1]), prev = a[1];
    for (int i = 2; i < n; ++i)
    {
        if (a[i] > 0)
        {
            return i + (minv >= a[i]);
        }
        minv = min(minv, abs(prev - a[i]));
        prev = a[i];
    }

    return n;
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
        vector<ll> a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
