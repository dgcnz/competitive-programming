#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    int ans = 2e9;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int         last = -1;
        vector<int> aor;
        for (int i = 0; i < n; ++i)
        {
            int b = (mask >> i) & 1;
            if (b == last)
                aor.back() |= a[i];
            else
                aor.push_back(a[i]), last = b;
        }
        ans = min(ans, accumulate(all(aor), 0, bit_xor<int>()));
    }
    cout << ans << endl;

    return 0;
}
