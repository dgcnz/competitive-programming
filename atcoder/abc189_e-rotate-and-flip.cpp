/** @file
 * @date                2021-01-25
 * @url                 https://url.com
 * @tags                implementation, linear_algebra
 * @status              AC
 * @score               0
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         60
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Note that you can describe each operation by a 3x3 transformation matrix.
 * Knowing this, you can store the result of the first $i$ operations, where
 * $0 \leq i \leq m$.
 *
 * @endidea
 */

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

template <typename T, int N, int M>
struct Matrix
{
    using allocator_type = array<array<T, M>, N>;
    using self           = Matrix<T, N, M>;
    allocator_type A;

    template <int R>
    Matrix<T, N, R> operator*(const Matrix<T, M, R> &B) const
    {
        Matrix<T, N, R> C;
        for (int i = 0; i < N; ++i)
            fill(all(C[i]), 0);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < R; ++j)
                for (int k = 0; k < M; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M> &B)
    {
        Matrix<T, N, M> C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[i][j] = A[i][j] + B[i][j];
    }

    template <typename V>
    Matrix<T, N, M> pow(V x) const
    {
        return *this;
    }

    array<T, M> &operator[](int i)
    {
        assert(0 <= i and i < N);
        return A[i];
    }

    const array<T, M> &operator[](int i) const
    {
        assert(0 <= i and i < N);
        return A[i];
    }

    Matrix<T, N, M> &operator=(array<array<T, N>, M> B)
    {
        A = B;
        return *this;
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<Matrix<ll, 3, 1>> X(n);

    for (auto &x : X)
        cin >> x[0][0] >> x[1][0], x[2][0] = 1;

    int m;
    cin >> m;

    vector<Matrix<ll, 3, 3>> A(m + 1);
    A[0] = {{{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}};

    for (int i = 1; i <= m; ++i)
    {
        int type;
        cin >> type;
        A[i] = [](int type) -> Matrix<ll, 3, 3> {
            int p;
            switch (type)
            {
            case 1:
                return {{{{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}}};
            case 2:
                return {{{{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}}};
            case 3:
                cin >> p;
                return {{{{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}}}};
            case 4:
                cin >> p;
                return {{{{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}}}};
            default:
                return {};
            }
        }(type)*A[i - 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b, b--;

        auto ans = A[a] * X[b];
        cout << ans[0][0] << " " << ans[1][0] << endl;
    }

    return 0;
}
