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

string solve(vi h, int m, int k)
{
    int n = h.size();
    for (int i = 0; i < n - 1; ++i)
    {
        auto new_hi = max(0, h[i + 1] - k);
        if (h[i + 1] > h[i] and new_hi - h[i] > m)
            return "NO";
        m += h[i] - new_hi;
        h[i] = new_hi;
    }
    return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vi h(n);
        read(all(h));
        cout << solve(h, m, k) << endl;
    }
    return 0;
}
