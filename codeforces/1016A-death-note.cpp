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

vector<ll> solve(vector<ll> a, ll m)
{
    int        n = a.size(), page = 0;
    vector<ll> ans(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int matched = min(m - page, a[i]);
        page += matched;
        a[i] -= matched;

        if (page == m)
        {
            ans[i]++;
            ans[i] += a[i] / m;
            page = a[i] % m;
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    read(all(a));

    auto ans = solve(a, m);
    write(all(ans), " "), cout << endl;
    return 0;
}
