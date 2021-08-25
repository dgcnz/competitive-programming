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
    vi p(n);
    read(all(p));
    sort(all(p));
    int ans = 0, sum = 0;
    for (; ans < n - 1; ++ans)
    {
        if (sum + p[ans] > p.back())
            break;
        sum += p[ans];
    }
    cout << ans + 1 << endl;
    return 0;
}
