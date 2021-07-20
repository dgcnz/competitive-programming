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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    int lcnt = k / 2;
    int rcnt = k / 2;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(' and lcnt)
        {
            cout << s[i];
            lcnt--;
        }
        if (s[i] == ')' and rcnt)
        {
            cout << s[i];
            rcnt--;
        }
    }
    return 0;
}
