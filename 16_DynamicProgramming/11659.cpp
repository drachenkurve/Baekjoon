#include <iostream>

using namespace std;

// 그냥 구간합 구하기
// 최대 누적합은 100000 * 1000 = 100000000

inline int sum[100001];

inline void solve()
{
	int n, m;
	cin >> n >> m;

	for (int nn = 1; nn <= n; ++nn)
	{
		int v;
		cin >> v;

		sum[nn] = sum[nn - 1] + v;
	}

	for (int mm = 1; mm <= m; ++mm)
	{
		int i, j;
		cin >> i >> j;

		cout << sum[j] - sum[i - 1] << '\n';
	}
}
