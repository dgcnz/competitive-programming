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
    int a, b, c;
    cin >> a >> b >> c;

    int const MAX = 1e5;
    for (int i = 1; i <= MAX; ++i)
    {
        int x = (a * 10) / b;
        if (x == c)
        {
            cout << i << endl;
            return 0;
        }
        a = (10 * a) % b;
    }
    cout << -1 << endl;
    return 0;
}
