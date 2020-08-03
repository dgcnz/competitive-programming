#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, u, v;
    cin >> n >> m;

    vector<int> deg(n, 0);

    while (m--)
    {
        cin >> u >> v, --u, --v;
        deg[u]++, deg[v]++;
    }

    for_each(deg.begin(), deg.end(), [](int x) { cout << x << endl; });
    return 0;
}
