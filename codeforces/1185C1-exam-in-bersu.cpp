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
    int n, m;
    cin >> n >> m;
    vi t(n);
    read(all(t));
    multiset<int> ord;
    ord.insert(t[0]);
    cout << 0;
    for (int i = 1; i < n; ++i)
    {
        int sum = m - t[i], cnt = i;
        for (auto x : ord)
        {
            if (sum - x < 0)
                break;
            sum -= x;
            cnt--;
        }
        ord.insert(t[i]);
        cout << " " << cnt;
    }
    cout << endl;
    return 0;
}
