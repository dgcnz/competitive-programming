#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool check(int x, int dsum)
{
    while (x)
    {
        dsum -= x % 10;
        x /= 10;
    }
    return dsum == 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi ans;
    for (int dsum = 1, x = n - dsum; x and dsum <= 300; ++dsum, x--)
        if (check(x, dsum))
            ans.push_back(x);
    cout << ans.size() << endl;
    write(rall(ans), " "), cout << endl;
    return 0;
}
