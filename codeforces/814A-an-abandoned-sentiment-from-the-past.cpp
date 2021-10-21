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

    vi a(n), b(k);
    read(all(a));
    read(all(b));

    sort(all(b));

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            a[i] = b.back();
            b.pop_back();
        }
    }

    cout << (is_sorted(all(a)) ? "No" : "Yes") << endl;
    return 0;
}
