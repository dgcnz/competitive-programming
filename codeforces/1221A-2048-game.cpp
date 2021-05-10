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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> cnt(32, 0);
        for (int i = 0; i < n; ++i)
        {
            int si;
            cin >> si;
            cnt[31 - __builtin_clz(si)]++;
        }
        for (int k = 0; k < 11; ++k)
            cnt[k + 1] += cnt[k] / 2;
        cout << (cnt[11] ? "YES" : "NO") << endl;
    }
    return 0;
}
