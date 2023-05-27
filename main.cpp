#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vi arr;
int m;

vvb dp;

void build() {
	for (auto i = 0; i < n; ++i) {
		dp[i][i] = true;

		if (n - 1 == i) {
			continue;
		}

		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = true;
		}
	}

	for (auto i = n - 1; 0 <= i; --i) {
		for (auto j = i + 2; j < n; ++j) {
			if (i + 1 == j) {
				continue;
			}

			if (arr[i] == arr[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	arr = vi(n);
	for (auto&& x : arr) {
		cin >> x;
	}

	dp = vvb(n, vb(n, false));
	build();

	cin >> m;
	while (0 < (m--)) {
		int s, e;
		cin >> s >> e;
		--s;
		--e;

		cout << (dp[s][e] ? 1 : 0) << '\n';
	}

	return 0;
}