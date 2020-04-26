#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, v;
    cin >> n;

    vi reported(n, false);

    for (int i = 0; i < n; ++i)
    {
        cin >> v;
        if (v == 0)
            reported[i] = true;
        else
            reported[v - 1] = true;
    }

    for (int i = 0; i < n; ++i)
        if (not reported[i])
            cout << i + 1 << " ";

    cout << endl;

    return 0;
}
