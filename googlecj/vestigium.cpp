#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int n;

int main(void)
{
    int t, rrows, rcols, trace, xij;
    cin >> t;

    for (int c = 1; c <= t; ++c)
    {
        rrows = rcols = trace = 0;
        cin >> n;

        set<int> cols[n];

        for (int i = 0; i < n; ++i)
        {
            set<int> crow;
            for (int j = 0; j < n; ++j)
            {
                cin >> xij;
                crow.insert(xij);
                cols[j].insert(xij);

                if (i == j)
                    trace += xij;
            }
            rrows += (n != crow.size());
        }

        for (int i = 0; i < n; ++i)
            rcols += (n != cols[i].size());

        cout << "Case #" << c << ": " << trace << " " << rrows << " " << rcols
             << endl;
    }
    return 0;
}
