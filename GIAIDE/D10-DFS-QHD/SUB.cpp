#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

const char* tfi = "SUB.INP";
const char* tfo = "SUB.OUT";
const int maxN = 100;

typedef int mang1[maxN + 1];
typedef int mang2[30001];
typedef char mang3[maxN + 1];

ifstream fi;
ofstream fo;
int N, T, S;
mang1 a;
bool good;
mang2 dd;
mang3 dau;

void Docdl() {
    fi.open(tfi);
    fi >> N >> T;
    for (int i = 1; i <= N; ++i) fi >> a[i];
    fi.close();

    S = 0;
    for (int i = 1; i <= N; ++i) S += a[i];
}

void Solve() {
    good = false;
    if (S + T - 2 * a[1] < 0) return;
    if (S + T - 2 * a[1] == 0) {
        good = true;
        goto _0;
    }
    memset(dd, 0, sizeof(dd));
    dd[0] = N + 1;
    int max_val = 0;
    for (int i = 3; i <= N; ++i) {
        int j = max_val;
        while (j >= 0) {
            if (dd[j] != 0 && dd[j + 2 * a[i]] == 0) {
                dd[j + 2 * a[i]] = i;
                if (j + 2 * a[i] > max_val) max_val = j + 2 * a[i];
                if (j + 2 * a[i] == S + T - 2 * a[1]) {
                    good = true;
                    goto _0;
                }
            }
            --j;
        }
    }
_0:
    if (!good) return;
    dau[1] = '+'; dau[2] = '-'; dau[N] = '-';
    for (int i = 3; i <= N; ++i) dau[i] = '-';
    int u = S + T - 2 * a[1];
    while (u > 0) {
        dau[dd[u]] = '+';
        u -= 2 * a[dd[u]];
    }
}

void Inkq() {
    fo.open(tfo);
    if (good) {
        int i = 3;
        while (i <= N) {
            while (i <= N && dau[i] == '+') {
                fo << i - 1 << endl;
                for (int j = i + 1; j <= N; ++j) dau[j - 1] = dau[j];
                --N;
            }
            ++i;
        }
        for (int i = 1; i <= N - 1; ++i) fo << 1 << endl;
    }
    fo.close();
}

int main() {
    Docdl();
    Solve();
    Inkq();
    return 0;
}
