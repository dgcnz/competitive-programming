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
    int n, k, m;
    cin >> n >> k >> m;

    vector<vi> rem(m);
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        rem[ai % m].push_back(ai);
    }

    for (int r = 0; r < m; ++r)
    {
        if ((int)rem[r].size() >= k)
        {
            cout << "Yes" << endl;
            rem[r].resize(k);
            write(all(rem[r]), " "), cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
