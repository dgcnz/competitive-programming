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
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int d   = x % 10;
        int ans = (d - 1) * 10;
        int cnt = 0;
        while (x)
        {
            x /= 10;
            cnt++;
        }
        cout << ans + (cnt * (cnt + 1)) / 2 << endl;
    }
    return 0;
}
