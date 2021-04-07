#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    int one_parity_cnt[2] = {0, 0};
    for (int i = 0; i < n; ++i)
    {
        int    one_cnt = 0;
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            one_cnt += s[j] == '1';
        one_parity_cnt[one_cnt % 2]++;
    }
    cout << ll(one_parity_cnt[0]) * one_parity_cnt[1] << endl;
    return 0;
}
