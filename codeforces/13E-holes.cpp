#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vi a(n);
    read(all(a));

    vector<int> steps(n);
    vector<int> last(n);
    vector<int> bix(2 * n);
    int const   BS = sqrt(n);

    int cbix = -1;

    for (int i = 0; i < 2 * n; ++i)
    {
        if (i % BS == 0 or i >= n)
            ++cbix;
        bix[i] = cbix;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (bix[i + a[i]] > bix[i])
            last[i] = i, steps[i] = 0;
        else
            last[i] = last[i + a[i]], steps[i] = 1 + steps[i + a[i]];
    }

    // dbg(bix, last, steps);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int i;
            cin >> i >> a[--i];
            for (int j = i; j >= 0 and bix[j] == bix[i]; j--)
            {
                if (bix[j + a[j]] > bix[j])
                    last[j] = j, steps[j] = 0;
                else
                    last[j] = last[j + a[j]], steps[j] = 1 + steps[j + a[j]];
            }
        }
        else
        {
            int i;
            cin >> i, i--;
            int ans = steps[i];
            i       = last[i];
            // dbg(last, steps, a);
            // dbg(i);
            while (i + a[i] < n)
            {
                ans += 1 + steps[i + a[i]], i = last[i + a[i]];
            }
            ans++;
            cout << i + 1 << " " << ans << "\n";
        }
    }
    return 0;
}
