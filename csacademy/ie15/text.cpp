#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool cmp(pair<char, int> x, pair<char, int> y) { return x.second < y.second; }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        int    k;
        cin >> a >> k;

        int n = a.size();

        vector<int> deleted(n, false);
        for (int d = 0; d <= 9; ++d)
        {
            if (k <= 0)
                break;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] == ('0' + d) and k > 0)
                {
                    deleted[i] = true;
                    k--;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (not deleted[i])
                cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}
