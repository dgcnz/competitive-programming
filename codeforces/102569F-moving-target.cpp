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

    vi ans;
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0 or i == n - 1)
            ans.push_back(i + 1);

    cout << ans.size() << endl;
    write(all(ans), " "), cout << endl;
    return 0;
}
