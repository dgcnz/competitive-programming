#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main(void)
{
    int       n, ai;
    stack<ii> S;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        while (!S.empty() and S.top().first >= ai)
            S.pop();

        if (S.empty())
            cout << "0 ";
        else
            cout << S.top().second + 1 << " ";

        S.push({ai, i});
    }

    return 0;
}
