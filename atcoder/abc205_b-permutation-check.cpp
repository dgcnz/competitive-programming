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
    int n;
    cin >> n;
    vi a(n);
    read(all(a));
    vector<int> vis(n, false);
    for (auto ai : a)
        vis[ai - 1] = true;

    if (all_of(all(vis), [](int ai) { return ai; }))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
