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

string solve(vector<int> l)
{
    sort(all(l));
    if (l[2] == l[1] + l[0])
        return "YES";
    for (int i = 0; i < 3; ++i)
        if (l[i] % 2 == 0 and l[(i + 1) % 3] == l[(i + 2) % 3])
            return "YES";
    return "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> l(3);
        read(all(l));
        cout << solve(l) << endl;
    }
    return 0;
}
