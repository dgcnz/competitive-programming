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

int solve(string s, int a, int b)
{
    int n = s.size(), ans = 0;

    if (b >= 0)
        ans = n * (a + b);
    else
    {
        vector<int> blocks[2];
        int         cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cnt++;
            if (i == n - 1 or s[i] != s[i + 1])
            {
                blocks[s[i] - '0'].push_back(cnt);
                cnt = 0;
            }
        }
        if (blocks[0].size() > blocks[1].size())
            swap(blocks[0], blocks[1]);
        for (auto len : blocks[0])
            ans += len * a + b;

        ans += accumulate(all(blocks[1]), 0) * a + b;
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
        int    n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        cout << solve(s, a, b) << endl;
    }
    return 0;
}
