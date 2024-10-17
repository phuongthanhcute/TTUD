#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Hàm tính giai thừa của một số nguyên
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

// Hàm tính tổ hợp chập k của n
long long combinations(int k, int n) {
    // Tính giai thừa của k và (n-k)
    long long factK = factorial(k);
    long long factNMinusK = factorial(n - k);

    // Tính tổ hợp chập k của n
    long long result = 1;
    for (int i = n; i > n - k; --i) {
        result = (result * i) % MOD;
    }
    result = (result * modularInverse(factK, MOD)) % MOD;
    result = (result * modularInverse(factNMinusK, MOD)) % MOD;

    return result;
}

// Hàm tính nghịch đảo modulo của một số
long long modularInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    // Áp dụng thuật toán Euclid mở rộng để tính nghịch đảo modulo
    while (a > 1) {
        // q là phần nguyên của a/m
        q = a / m;
        t = m;
        // m là phần dư của a/m
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    int k, n;
    cin >> k >> n;

    // Tính tổ hợp chập k của n modulo 10^9 + 7
    long long result = combinations(k, n);
    cout << result << endl;

    return 0;
}
