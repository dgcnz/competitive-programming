#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi a)
{
    int         n = a.size();
    vector<int> amax(n);

    vector<bool> record(n, false);
    for (int i = 0; i < n; ++i)
    {
        amax[i]   = i > 0 ? max(a[i], amax[i - 1]) : a[i];
        record[i] = a[i] >= amax[i];
    }

    int base = accumulate(all(record), 0);
    ii  ans  = {0, 0};
    for (int i = 0; i < n; ++i)
        if (record[i] == 0)
            ans = max(ans, {base, -a[i]});

    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n and record[j] == 0)
            ++j;
        i = j++;
        if (i == n)
            break;

        ii  cur = {base - 1, -a[i]};
        int mx  = i >= 1 ? amax[i - 1] : -1;
        while (j < n and record[j] == 0)
        {
            if (a[j] > mx)
                cur.first++;
            mx = max(mx, a[j]);
            ++j;
        }
        ans = max(ans, cur);
        i++;
    }
    return abs(ans.second) + 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));
    decrement(all(a));

    cout << solve(a) << endl;

    return 0;
}
