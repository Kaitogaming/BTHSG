#include <bits/stdc++.h>

#define nl '\n'

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

#define TASK "vuon"
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  std::vector<std::vector<int>> res(n, std::vector<int>(m));

  auto solve = [&]() {
    std::vector<int> h(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        h[j] = a[i][j] == 1 ? h[j] + 1 : 0;
      }

      std::vector<int> L(m), R(m);

      for (int j = 0; j < m; j++) {
        L[j] = j - 1;
        while (L[j] > -1 && h[L[j]] >= h[j]) {
          L[j] = L[L[j]];
        }
      }

      for (int j = m - 1; j >= 0; j--) {
        R[j] = j + 1;
        while (R[j] < m && h[R[j]] >= h[j]) {
          R[j] = R[R[j]];
        }
      }

      for (int j = 0; j < m; j++) {
        int area = h[j] * (R[j] - L[j] - 1);
        for (int k = 0; k < h[j]; k++) {
          res[i - k][j] = std::max(res[i - k][j], area);
        }
      }
    }
  };

  solve();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] ^= 1;
    }
  }

  solve();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << res[i][j] << " ";
    }
    std::cout << nl;
  }

}
