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

string solve(vi p)
{
    int         n = p.size();
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
    {
        p[i]--;
        pos[p[i]] = i;
    }

    string ans(n, '0');
    ans[0] = '1';
    int l = pos[0], r = pos[0];
    for (int i = 1; i < n; ++i)
    {
        int j = pos[i];
        if (j > r)
            r = j;
        else if (j < l)
            l = j;
        if (r - l + 1 == i + 1)
            ans[i] = '1';
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

        vi p(n);

        read(all(p));
        cout << solve(p) << endl;
    }
    return 0;
}
