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
    int n;
    cin >> n;
    vector<int> cnt(2, 0);
    while (n--)
    {
        int x, y;
        cin >> x >> y;

        cnt[x < 0]++;
    }

    if (cnt[0] > 1 and cnt[1] > 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}
