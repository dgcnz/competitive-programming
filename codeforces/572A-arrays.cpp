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
    int na, nb;
    cin >> na >> nb;
    int k, m;
    cin >> k >> m;

    vi a(na), b(nb);
    read(all(a));
    read(all(b));

    int l = a[k - 1], r = b[nb - m];
    if (l < r)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
