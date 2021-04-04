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
    int maxv = *max_element(all(a)), n = a.size();
    if (a[0] == maxv and a[1] != maxv)
        return 1;
    if (a[n - 1] == maxv and a[n - 2] != maxv)
        return n;

    for (int i = 1; i < n - 1; ++i)
        if (a[i] == maxv and (a[i - 1] != maxv or a[i + 1] != maxv))
            return i + 1;
    return -1;
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
