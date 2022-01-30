#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        read(all(a));
        read(all(b));

        auto sigma = argsort(all(a));
        a          = apply_permutation(all(a), sigma);
        b          = apply_permutation(all(b), sigma);

        int i = 0;
        while (i < n and k >= a[i])
            k += b[i++];
        cout << k << endl;
    }
    return 0;
}
