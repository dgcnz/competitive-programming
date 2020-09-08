#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);

        for (auto &ai : a)
            cin >> ai;

        sort(all(a), greater<int>());
        vi           ans = {a[0]};
        vector<bool> visited(n, false);

        int i = 1;
        while (i < n and a[i] == a[0])
        {
            visited[i] = true;
            ans.push_back(a[i]);
            ++i;
        }

        int agcd = a[0];
        while (isz(ans) < n)
        {
            int ix, g = 1;
            for (int j = i; j < n; ++j)
            {
                if (visited[j])
                    continue;
                if (gcd(agcd, a[j]) > g)
                {
                    g  = gcd(agcd, a[j]);
                    ix = j;
                }
            }
            if (g == 1)
            {
                for (int j = i; j < n; ++j)
                {
                    if (not visited[j])
                    {
                        ans.push_back(a[j]);
                        visited[j] = true;
                    }
                }
            }
            else
            {
                visited[ix] = true;
                ans.push_back(a[ix]);
                agcd = gcd(agcd, g);
            }
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
