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

bool solve(string s)
{
    int n = s.size(), turns = (n - 11) / 2, eights = 0;
    for (int i = 0; i <= turns * 2; ++i)
        if (s[i] == '8')
            eights++;

    // dbg(eights, turns);
    if (eights <= turns)
        return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> n >> s;

    cout << (solve(s) ? "YES" : "NO") << endl;
    return 0;
}
