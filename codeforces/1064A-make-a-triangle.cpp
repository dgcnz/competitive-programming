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
    vi a(3);
    read(all(a));
    sort(all(a));
    if (a[2] < a[0] + a[1])
        cout << 0 << endl;
    else
        cout << a[2] - (a[1] + a[0]) + 1 << endl;
    return 0;
}
