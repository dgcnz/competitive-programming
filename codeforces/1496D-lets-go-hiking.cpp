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

int solve(vector<int> p)
{
    int n = p.size(), mx = 0;

    vector<int> options, cnt(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        if ((i == 0 or p[i - 1] < p[i]) and (i == n - 1 or p[i] > p[i + 1]))
        {
            int l = 1, r = 1;
            for (int j = i - 1; j >= 0 and p[j] < p[j + 1]; j--)
                l++;
            for (int j = i + 1; j < n and p[j] < p[j - 1]; j++)
                r++;
            cnt[l]++, cnt[r]++;
            mx = max({mx, l, r});
            if (l == r)
                options.push_back(l);
        }
    }
    if (options.empty())
        return 0;
    int len = *max_element(all(options));
    if (cnt[len] > 2 or len % 2 == 0 or len != mx)
        return 0;
    else
        return 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n);
    read(all(p));
    cout << solve(p) << endl;
    return 0;
}
