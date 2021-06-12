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
    vector<string> hashtags(n);
    read(all(hashtags));
    for (int i = n - 2; i >= 0; i--)
    {
        if (hashtags[i + 1] >= hashtags[i])
            continue;
        for (int j = 1; j < (int)hashtags[i].size(); j++)
        {
            if (j > (int)hashtags[i + 1].size() - 1 or
                hashtags[i + 1][j] < hashtags[i][j])
            {
                hashtags[i].resize(j);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)hashtags[i].size(); j++)
            cout << hashtags[i][j];
        cout << endl;
    }
    return 0;
}
