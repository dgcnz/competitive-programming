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

string solve(int n, int a, int x, int b, int y)
{
    vector<int> t1(n, -1), t2(n, -1);
    int         t = 0;
    for (; (a + t) % n != x; ++t)
        t1[(a + t) % n] = t;
    t1[x] = t;

    t = 0;
    for (; (b - t + n) % n != y; ++t)
        t2[(b - t + n) % n] = t;
    t2[y] = t;

    for (int i = 0; i < n; ++i)
        if (t1[i] == t2[i] and t1[i] != -1)
            return "YES";
    return "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y, a--, x--, b--, y--;
    cout << solve(n, a, x, b, y) << endl;
    return 0;
}
