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
    int n;
    cin >> n;

    vector<ii> last_balance(n);
    for (auto &[t, x] : last_balance)
        t = 0, cin >> x;

    int q;
    cin >> q;

    vector<int> payouts(q + 1, 0);
    for (int i = 1; i <= q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int p, x;
            cin >> p >> x, p--;
            last_balance[p] = {i, x};
        }
        else
        {
            int x;
            cin >> x;
            payouts[i] = x;
        }
    }

    vector<int> maxpayout(q + 1);
    maxpayout[q] = payouts[q];
    for (int i = q - 1; i >= 0; --i)
        maxpayout[i] = max(payouts[i], maxpayout[i + 1]);

    for (auto [t, x] : last_balance)
        cout << max(x, maxpayout[t]) << " ";

    return 0;
}
