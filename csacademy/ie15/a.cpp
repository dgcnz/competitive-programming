#include <bits/stdc++.h>
#include <dbg.h>

using namespace std;

double getDeterminantBareiss(std::vector<std::vector<double>> vect)
{
    int dim = vect.size();

    if (dim <= 0)
    {
        return 0;
    }

    double sign = 1;

    for (int k = 0; k < dim - 1; k++)
    {

        // Pivot - row swap needed
        if (vect[k][k] == 0)
        {
            int m = 0;
            for (m = k + 1; m < dim; m++)
            {
                if (vect[m][k] != 0)
                {
                    swap(vect[m], vect[k]);
                    sign = -sign;
                    break;
                }
            }

            // No entries != 0 found in column k -> det = 0
            if (m == dim)
            {
                return 0;
            }
        }

        // Apply formula
        for (int i = k + 1; i < dim; i++)
        {
            for (int j = k + 1; j < dim; j++)
            {
                vect[i][j] = vect[k][k] * vect[i][j] - vect[i][k] * vect[k][j];
                if (k != 0)
                {
                    vect[i][j] /= vect[k - 1][k - 1];
                }
            }
        }
    }

    int n = vect.size(), m = vect[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return sign * vect[dim - 1][dim - 1];
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<double>> a(n, vector<double>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    auto det = getDeterminantBareiss(a);
    cout << det << endl;

    return 0;
}
