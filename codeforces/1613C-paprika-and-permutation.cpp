#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<int> a)
{
    int n = a.size();
    sort(all(a));

    int          ans = 0;
    vector<bool> vis(n + 1, false);
    vector<int>  rem;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= n and not vis[a[i]])
            vis[a[i]] = true;
        else
            rem.push_back(a[i]);
    }

    reverse(all(rem));
    for (int x = 1; x <= n; ++x)
    {
        if (vis[x])
            continue;

        int y  = rem.back();
        int ub = (y - 1) / 2;
        rem.pop_back();

        if (ub < x)
            return -1;
        ans++;
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
        int n;
        cin >> n;
        vi a(n);
        read(all(a));

        cout << solve(a) << endl;
    }
    return 0;
}
