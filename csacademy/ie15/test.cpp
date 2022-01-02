
#ifndef Level
#define Level 3
#endif

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;
// #include "CORE.h"

class Matrix
{
  private:
    int     n;
    double *_rep;

  public:
    Matrix(int d) : n(d) { _rep = new double[n * n]; }
    Matrix(int d, double M[]);
    Matrix(int d, int M[]);
    Matrix(const Matrix &);
    const Matrix &operator=(const Matrix &);
    ~Matrix() { delete[] _rep; }
    const double &  operator()(int r, int c) const { return _rep[r * n + c]; }
    double &        operator()(int r, int c) { return _rep[r * n + c]; }
    double          determinant() const;
    friend ostream &operator<<(ostream &, const Matrix &);
};

Matrix::Matrix(int d, double M[]) : n(d)
{
    int i, j;
    _rep = new double[n * n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            _rep[i * n + j] = M[i * n + j];
}
Matrix::Matrix(int d, int M[]) : n(d)
{
    int i, j;
    _rep = new double[n * n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            _rep[i * n + j] = M[i * n + j];
}

Matrix::Matrix(const Matrix &M) : n(M.n)
{
    int i, j;
    _rep = new double[n * n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            _rep[i * n + j] = M._rep[i * n + j];
}

const Matrix &Matrix::operator=(const Matrix &M)
{
    int i, j;
    if (n != M.n)
    {
        delete[] _rep;
        n    = M.n;
        _rep = new double[n * n];
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            _rep[i * n + j] = M._rep[i * n + j];
    return *this;
}

double Matrix::determinant() const
{
    Matrix A = *this;
    double det;
    int    i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        // assert(a(i, i) == 0);
        for (j = i + 1; j < n; j++)
            for (k = i + 1; k < n; k++)
            {
                A(j, k) = (A(j, k) * A(i, i) - A(j, i) * A(i, k));
                if (i)
                    A(j, k) /= A(i - 1, i - 1);
            }
    }

    return A(n - 1, n - 1);
}

ostream &operator<<(ostream &o, const Matrix &M)
{
    int i, j;
    for (i = 0; i < M.n; i++)
    {
        for (j = 0; j < M.n; j++)
        {
            double d = M(i, j);
            o << M(i, j) << " ";
            o << d << endl;
        }
        o << endl;
    }
    return o;
}

int main(int argc, char *argv[])
{
    double e, f;

    double A[] = {512.0,
                  512.0,
                  512.0,
                  1.0,
                  512.0,
                  -512.0,
                  -512.0,
                  1.0,
                  -512.0,
                  512.0,
                  -512.0,
                  1.0,
                  -512.0,
                  -512.0,
                  512.0,
                  1.0};
    Matrix m(4, A);
    e = m.determinant();
    cout << "Determinant of A = " << e << endl;
    cout << "  Note: Determinant of A will overflow in Level 1 \n\n";

    double B[] = {1.0,
                  1.0,
                  0.0,
                  0.0,
                  0.0,
                  1.0,
                  1.0,
                  0.0,
                  0.0,
                  0.0,
                  1.0,
                  1.0,
                  0.0,
                  0.0,
                  0.0,
                  1.0};
    Matrix n(4, B);
    f = n.determinant();
    cout << "Determinant of B = " << f << endl;
    cout << "  Note: Determinant of B should be 0, but shows non-zero in Level "
            "1\n\n";

    return 0;
}
