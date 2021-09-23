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

    vector<int> cnt(k);
    for (int i = 0; i < n; ++i)
        cnt[s[i] - 'A']++;

    int ans = k * *min_element(all(cnt));
    cout << ans << endl;
    return 0;
}
