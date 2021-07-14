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
    int    n, k;
    string s;
    cin >> n >> k >> s;

    sort(all(s));

    int  ans = 0, cnt = 0;
    char prv = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] - prv >= 2 and cnt < k)
        {
            ans += s[i] - 'a' + 1;
            prv = s[i];
            cnt++;
        }
    }
    if (cnt == k)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
