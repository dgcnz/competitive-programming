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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    read(all(a)), read(all(b));

    int acc_a = accumulate(all(a), 0, bit_xor<int>());
    int acc_b = accumulate(all(b), 0, bit_xor<int>());

    if (acc_a != acc_b)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    vector<vi> c(n, vi(m, 0));

    for (int i = 1; i < m; ++i)
        c[0][i] = b[i];

    for (int i = 1; i < n; ++i)
        c[i][0] = a[i];

    c[0][0] = a[0] ^ b[0] ^ acc_b;

    for (auto &cr : c)
        write(all(cr), " "), cout << endl;

    return 0;
}
