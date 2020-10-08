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
        int n, k;
        cin >> n >> k;

        vi a(n);
        for (auto &ai : a)
            cin >> ai;

        if (any_of(all(a), [k](int ai) { return ai > k; }))
        {
            cout << -1 << endl;
            continue;
        }

        ll acc = 0, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (acc + a[i] > k)
            {
                ans++;
                acc = 0;
            }
            acc += a[i];
        }

        cout << ans + (acc > 0) << endl;
    }
    return 0;
}
