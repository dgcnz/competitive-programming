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
    int k;
    cin >> k;

    string vowels = "aeiou";

    for (int n = 5; n <= k; ++n)
    {
        int m = k / n;
        if (k % n == 0 and m >= 5)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    cout << vowels[(i + j) % 5];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
