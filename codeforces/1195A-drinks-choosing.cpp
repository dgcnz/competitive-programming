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
    int n, k;
    cin >> n >> k;

    vector<int> cnt(k + 1);
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        cnt[ai]++;
    }

    int sets = (n + 1) / 2, ans = 0;
    for (auto &dcnt : cnt)
    {
        int pairs = dcnt / 2;
        ans += 2 * pairs;
        sets -= pairs;
        dcnt %= 2;
    }

    for (auto &dcnt : cnt)
    {
        if (dcnt == 0)
            continue;
        if (sets == 0)
            break;
        ans += 1;
        sets -= 1;
        dcnt--;
    }

    cout << ans << endl;

    return 0;
}
