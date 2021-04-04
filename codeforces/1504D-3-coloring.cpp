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

    vector<vector<ii>> rem(2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rem[(i + j) % 2].emplace_back(i, j);

    vector<ii> choices = {{1, 2}, {0, 2}, {0, 1}};

    while (rem[0].size() or rem[1].size())
    {
        int x;
        cin >> x, x--;
        auto [y, z] = choices[x];
        if (rem[y].size())
        {
            auto [i, j] = rem[y].back();
            rem[y].pop_back();
            cout << y + 1 << " " << i + 1 << " " << j + 1 << endl;
        }
        else
        {
            y           = 1 - y;
            auto [i, j] = rem[y].back();
            rem[y].pop_back();
            cout << z + 1 << " " << i + 1 << " " << j + 1 << endl;
        }
        cout.flush();
    }

    return 0;
}
