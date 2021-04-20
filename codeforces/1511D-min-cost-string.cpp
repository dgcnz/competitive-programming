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

string solve(int n, int k)
{
    int         m = 0;
    vector<int> base(k * k, 0);
    for (int i = 0; i < k - 1; ++i)
    {
        base[m++] = i;
        for (int j = i + 1; j < k; ++j)
            base[m++] = i, base[m++] = j;
    }
    base[m++] = k - 1;

    string s(n, ' ');
    for (int i = 0; i < n; ++i)
        s[i] = 'a' + base[i % m];
    return s;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
