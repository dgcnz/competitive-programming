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

vi solve(string a, string b)
{
    int n = a.size();
    a += '0';
    b += '0';
    vi ops1, ops2;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            ops1.push_back(i);
        if (b[i] != b[i - 1])
            ops2.push_back(i);
    }
    ops1.insert(ops1.end(), ops2.rbegin(), ops2.rend());
    return ops1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string a, b;
        cin >> n >> a >> b;
        auto ans = solve(a, b);
        cout << ans.size() << " ";
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
