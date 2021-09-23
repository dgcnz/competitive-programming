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
    if (n <= 2)
    {
        cout << "No" << endl;
    }
    else
    {
        int x = (n + 1) / 2;
        cout << "Yes" << endl;
        cout << 1 << " " << x << endl;

        cout << n - 1 << " ";
        for (int i = 1; i <= n; ++i)
            if (i != x)
                cout << i << " ";
        cout << endl;
    }

    return 0;
}
