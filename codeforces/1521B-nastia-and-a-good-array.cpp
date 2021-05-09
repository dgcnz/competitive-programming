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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(all(a));
        cout << n - 1 << endl;
        int i = distance(a.begin(), min_element(all(a)));
        for (int j = i - 1; j >= 0; --j)
        {
            cout << j + 1 << " " << i + 1 << " " << a[i] + (i - j) << " "
                 << a[i] << endl;
        }
        for (int j = i + 1; j < n; ++j)
        {
            cout << i + 1 << " " << j + 1 << " " << a[i] << " "
                 << a[i] + (j - i) << endl;
        }
    }
    return 0;
}
