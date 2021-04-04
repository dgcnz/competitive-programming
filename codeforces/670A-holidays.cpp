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

    int mn(0), mx(0);
    for (int i = 1; i <= n; i += 7)
    {
        mn += (i + 5 <= n) + (i + 6 <= n);
        mx += (i <= n) + (i + 1 <= n);
    }
    cout << mn << " " << mx << endl;
    return 0;
}
