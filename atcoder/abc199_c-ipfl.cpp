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
    int    n, q;
    string s;
    cin >> n >> s >> q;

    string s1(s.begin(), s.begin() + n), s2(s.begin() + n, s.end());
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b, a--, b--;
        if (t == 1)
        {
            auto &ca = (a < n ? s1[a] : s2[a - n]);
            auto &cb = (b < n ? s1[b] : s2[b - n]);
            swap(ca, cb);
        }
        else
            s1.swap(s2);
    }
    cout << s1 << s2 << endl;
    return 0;
}
