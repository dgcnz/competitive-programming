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
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];

    int k;
    cin >> k;
    int read = lower_bound(all(r), k) - r.begin();
    cout << n - read << endl;
    return 0;
}
