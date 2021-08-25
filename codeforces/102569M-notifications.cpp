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

    ll finish_time = 0;
    while (n--)
    {
        ll t, d;
        cin >> t >> d;
        if (finish_time < t)
            finish_time = t + d;
        else
            finish_time += d;
    }
    cout << finish_time << endl;
    return 0;
}
