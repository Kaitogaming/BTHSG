#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 19;
const int MAX_A = 30;
const int MAX_B = 19;
const int MAX_C = 13;
const int MAX_D = 11;

long long memo[MAX_DIGITS][MAX_A][MAX_B][MAX_C][MAX_D];
int f[] = {2, 3, 5, 7};
int k[] = {0, 0, 0, 0};
int code[10][5] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {2, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {3, 0, 0, 0},
    {0, 2, 0, 0}
};

long long rec(int digits, long long a, long long pot, long long lo, long long hi) {
    long long b = a + pot - 1;
    if (a > hi || b < lo) {
        return 0;
    }
    if (digits == 18) {
        if (k[0] > 0 || k[1] > 0 || k[2] > 0 || k[3] > 0) {
            return 0;
        } else {
            return 1;
        }
    }
    bool memoize = (a >= lo) && (b <= hi);
    if (memoize && memo[digits][k[0]][k[1]][k[2]][k[3]] >= 0) {
        return memo[digits][k[0]][k[1]][k[2]][k[3]];
    }
    pot /= 10;
    long long result = 0;
    for (int digit = 0; digit < 10; ++digit) {
        if (digit == 0 && a != 0) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i < 4; ++i) {
            if (code[digit][i] > k[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            k[i] -= code[digit][i];
        }
        result += rec(digits + 1, a + digit * pot, pot, lo, hi);
        for (int i = 0; i < 4; ++i) {
            k[i] += code[digit][i];
        }
    }
    if (memoize) {
        memo[digits][k[0]][k[1]][k[2]][k[3]] = result;
    }
    return result;
}

long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

long long floor_div(long long a, long long b) {
    return a / b;
}

void generate(long long limit, long long product, int factor, long long lo, long long hi, long long &rjesenje) {
    if (product > 1000000000 || product * product > limit) {
        return;
    }
    if (factor > 4) {
        rjesenje += rec(0, 0, 1000000000000000000LL, ceil_div(lo, product), floor_div(hi, product));
    } else {
        generate(limit, product, factor + 1, lo, hi, rjesenje);
        ++k[factor - 1];
        generate(limit, product * f[factor - 1], factor, lo, hi, rjesenje);
        --k[factor - 1];
    }
}

int main() {
    freopen("TICH.INP", "r", stdin);
    freopen("TICH.OUT", "w", stdout);

    long long lo, hi, rjesenje = 0;
    cin >> lo >> hi;

    for (int dig = 0; dig < MAX_DIGITS; ++dig) {
        for (int a = 0; a < MAX_A; ++a) {
            for (int b = 0; b < MAX_B; ++b) {
                for (int c = 0; c < MAX_C; ++c) {
                    for (int d = 0; d < MAX_D; ++d) {
                        memo[dig][a][b][c][d] = -1;
                    }
                }
            }
        }
    }

    generate(hi, 1, 1, lo, hi, rjesenje);

    cout << rjesenje << endl;

    return 0;
}
