#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main(void)
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<bool> ok(n, false);
        vector<int>  sorted, ans(n), a(n);

        for (auto &ai : a)
            cin >> ai;

        int minv = *min_element(a.begin(), a.end());

        for (int i = 0; i < n; ++i)
        {
            if (gcd(a[i], minv) == minv)
            {
                ok[i] = true;
                sorted.push_back(a[i]);
            }
        }

        int j = 0;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; ++i)
        {
            if (ok[i])
                ans[i] = sorted[j++];
            else
                ans[i] = a[i];
        }

        cout << (is_sorted(ans.begin(), ans.end()) ? "YES" : "NO") << endl;
    }
    return 0;
}
