class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<long long> multiplyMatVec(const Matrix& M,
                                     const vector<long long>& v) {
        int n = M.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0) continue;

                res[i] = (res[i] + M[i][j] * v[j]) % MOD;
            }
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int K = 2 * m;

        Matrix T(K, vector<long long>(K, 0));

        // U' = A * D
        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                T[v][m + u] = 1;
            }
        }

        // D' = B * U
        for (int v = 0; v < m; v++) {
            for (int u = v + 1; u < m; u++) {
                T[m + v][u] = 1;
            }
        }

        vector<long long> base(K, 0);

        // Length = 2 state
        for (int v = 1; v <= m; v++) {
            base[v - 1] = v - 1;      // U2(v)
            base[m + v - 1] = m - v;  // D2(v)
        }

        Matrix P = power(T, n - 2);

        vector<long long> state = multiplyMatVec(P, base);

        long long ans = 0;
        for (long long x : state) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};