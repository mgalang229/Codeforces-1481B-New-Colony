#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		if (n * (int) *max_element(h.begin(), h.end()) < k) {
			cout << -1 << '\n';
			continue;
		}
		
		//k = 53
		//4 11 2 2 12 3 1 2 7 6 5 8
		//11 11 2 3 12 3 1 2 7 6 5 8
		//11 11 3 3 12 3 1 2 7 6 5 8
		//11 11 3 4 12 3 1 2 7 6 5 8
		//11 11 4 4 12 3 1 2 7 6 5 8
		//11 11 4 5 12 3 1 2 7 6 5 8
		//11 11 5 5 12 3 1 2 7 6 5 8
		//.
		//.
		//.
		//11 12 12 12 12 3 1 2 7 6 5 8
		//12 12 12 12 12 3 1 2 7 6 5 8
		
		int ans = n + 1;
		for (int boulder = 0; boulder < k; boulder++) {
			int to = -2;
			for (int i = 0; i < n - 1; i++) {
				if (h[i] < h[i + 1]) {
					to = i;
					break;
				}
			}
			ans = to + 1;
			if (to == -2) {
				break;
			}
			h[to]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
