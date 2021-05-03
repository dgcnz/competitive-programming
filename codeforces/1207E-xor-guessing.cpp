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
    vi a01(100);
    vi a10(100);
    iota(all(a01), 1);
    iota(all(a10), 1);
    transform(all(a10), begin(a10), [](int ai) { return ai << 7; });

    cout << "? ";
    write(all(a01), " "), cout << endl;
    cout.flush();

    int x01;
    cin >> x01;

    cout << "? ";
    write(all(a10), " "), cout << endl;
    cout.flush();

    int x10;
    cin >> x10;

    x01 = (x01 >> 7) << 7;
    x10 ^= ((x10 >> 7) << 7);

    cout << "! " << x01 + x10 << endl;

    return 0;
}
