#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi p(n);
    read(all(p));
    transform(all(p), begin(p), [](int pi) { return pi - 1; });
    cout << 1 << " ";

    fenwick_tree<int> ft(n);

    set<int> w;
    for (int i = 0; i < n; ++i)
        w.insert(i);
    for (int i = 0; i < n - 1; ++i)
    {
        ft.add(p[i], 1);
        w.erase(p[i]);
        cout << 1 + ft.sum(0, *w.rbegin()) << " ";
    }
    cout << 1 << endl;
    return 0;
}
