#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // pos[x] : position of last occurence of x
    
    vi a(n + 1), pos(n + 1), ans;
    vb vis(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (vis[a[i]])
            continue;
        // while the last number in our sequence is greater than our current
        // number and such last number may appear later in the string
        while (not ans.empty() and a[i] < ans.back() and i < pos[ans.back()])
        {
            vis[ans.back()] = false;
            ans.pop_back();
        }
        ans.push_back(a[i]);
        vis[a[i]] = true;
    }

    for (int i = 0, len = (int)ans.size(); i < len; ++i)
        cout << ans[i] << (i < len - 1 ? " " : "");
    cout << endl;
    return 0;
}
