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
        int n, k;
        cin >> n >> k;
        vi a(n);
        read(all(a));
        ll extra = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int take = min(a[i], k);
            a[i] -= take;
            extra += take;
            k -= take;
        }
        a[n - 1] += extra;
        write(all(a), " "), cout << endl;
    }
    return 0;
}
