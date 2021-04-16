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
        map<int, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            cnt[ai]++;
        }
        auto min = cnt.begin()->first;
        int  ans = 0;
        for (auto [k, v] : cnt)
            if (k != min)
                ans += v;
        cout << ans << endl;
    }
    return 0;
}
