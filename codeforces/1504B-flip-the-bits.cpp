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

bool solve(string a, string b)
{
    int n = a.size();

    int first = 0;
    vi  cnt(2, 0);

    for (int i = 0; i < n; ++i)
    {
        cnt[a[i] - '0']++;
        if (cnt[0] == cnt[1])
        {
            bool flag = true;
            for (int j = first; j <= i; ++j)
                if (a[j] != b[j])
                    flag = false;
            if (not flag)
            {
                for (int j = first; j <= i; ++j)
                {
                    if (a[j] == b[j])
                        return false;
                    else
                        a[j] = b[j];
                }
            }
            first = i + 1;
        }
    }
    return a == b;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << (solve(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
