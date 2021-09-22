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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> dp(m - n + 1);
    for (int j = 0; j + n <= m; ++j)
        for (int i = 0; i < n; ++i)
            dp[j] += s[i] != t[j + i];

    int ix = min_element(all(dp)) - dp.begin();

    vector<int> ans;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != t[ix + i])
            ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    write(all(ans), " "), cout << endl;

    return 0;
}
