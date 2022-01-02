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

    vector<int> f = {1, 1, 2, 6};
    string      s;
    cin >> s;

    int ans = f[3];
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    ans /= f[3 - (int)s.size() + 1];
    cout << ans << endl;
    return 0;
}
