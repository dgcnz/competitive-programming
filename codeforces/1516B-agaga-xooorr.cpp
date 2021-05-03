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

bool solve(vi a)
{
    int n = a.size();
    vi  pa(n);
    partial_sum(all(a), pa.begin(), bit_xor<int>());
    if (pa[n - 1] == 0)
        return true;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            int x = pa[i], y = pa[j] ^ pa[i], z = pa[n - 1] ^ pa[j];
            if (x == y and x == z)
                return true;
        }
    }
    return false;
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
        vi a(n);
        read(all(a));
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
