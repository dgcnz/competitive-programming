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

int solve(vi a)
{
    int n = a.size(), cnt = (a[0] == 1), ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] == 1)
            cnt++;
        else
        {
            ans = max(ans, cnt - 1);
            cnt = 0;
        }
    }
    if (cnt)
        ans = max(ans, cnt - (a.back() == 1000 ? 0 : 1));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    cout << solve(a) << endl;
    return 0;
}
