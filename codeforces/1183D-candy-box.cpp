#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi cnt(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            cnt[ai]++;
        }

        multiset<int, greater<int>> s;
        for (int i = 1; i <= n; ++i)
            if (cnt[i] > 0)
                s.insert(cnt[i]);

        int cur = *s.begin(), ans = 0;
        for (auto x : s)
        {
            ans += min(cur, x);
            cur = min(cur, x);
            cur--;
            if (cur == 0)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
