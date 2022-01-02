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
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, L, a;
    cin >> n >> L >> a;

    int ct  = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int ti, li;
        cin >> ti >> li;
        int free_time = ti - ct;
        ans += free_time / a;
        ct = ti + li;
    }

    if (ct <= L)
        ans += (L - ct) / a;

    cout << ans << endl;
    return 0;
}
