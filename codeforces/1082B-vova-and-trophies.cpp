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

int solve(string s)
{
    int n = s.size(), total_golden = 0;
    s = 'S' + s + 'S';
    vector<int> id(n + 2, 0), sz(n + 2, 0);

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'G')
        {
            if (s[i - 1] == 'G')
                id[i] = id[i - 1];
            else
                id[i] = i;
            sz[id[i]]++;
            total_golden++;
        }
    }
    if (total_golden == n)
        return n;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'S')
        {
            int l = sz[id[i - 1]], r = sz[id[i + 1]];
            ans = max(ans, l + r + (l + r < total_golden));
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
