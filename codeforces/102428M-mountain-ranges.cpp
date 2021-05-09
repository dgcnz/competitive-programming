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
    int n, x;
    cin >> n >> x;
    vi a(n);
    read(all(a));

    int ans = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        int j = i + 1;
        while (j < n and a[j] - a[j - 1] <= x)
            ++j;
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}
