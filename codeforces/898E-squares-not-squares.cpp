#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    int n;
    cin >> n;

    vector<ii> diff;
    for (int i = 0; i < n; ++i)
    {
        ll ai, sq;
        cin >> ai;
        sq = round(sqrt(ai));
        diff.emplace_back(abs(ai - sq * sq), ai);
    }
    sort(all(diff));

    ll ans = 0;
    for (int i = 0; i < n / 2; ++i)
        ans += diff[i].first;
    for (int i = n / 2; i < n; ++i)
        ans += (diff[i].first != 0 ? 0 : 1 + !diff[i].second);
    cout << ans << endl;

    return 0;
}
