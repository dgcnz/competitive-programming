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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vi> cnt(26, vi(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int c = 0; c < 26; ++c)
            cnt[c][i] += (i > 0 ? cnt[c][i - 1] : 0);
        cnt[s[i] - 'a'][i]++;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r, l--, r--;

        ll ans = 0;
        for (int c = 0; c < 26; ++c)
            ans += (c + 1) * ll(cnt[c][r] - (l > 0 ? cnt[c][l - 1] : 0));
        cout << ans << endl;
    }
    return 0;
}
