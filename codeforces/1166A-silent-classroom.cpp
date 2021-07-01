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

ll c2(ll n) { return (n * (n - 1)) / 2; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;
        cnt[name[0] - 'a']++;
    }

    ll ans = 0;
    for (auto c : cnt)
        if (c)
            ans += c2(c / 2) + c2(c - c / 2);
    cout << ans << endl;
    return 0;
}
