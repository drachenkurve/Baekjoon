#include <algorithm>
#include <iostream>

using namespace std;

// 1번 집
// R
// G
// B
//
// 2번 집
// R -> G
// R -> B
// G -> R
// G -> B
// B -> R
// B -> G
//
// 3번 집
// R -> G -> R
// R -> G -> B
// R -> B -> R
// R -> B -> G
// G -> R -> G
// G -> R -> B
// G -> B -> R
// G -> B -> G
// B -> R -> G
// B -> R -> B
// B -> G -> R
// B -> G -> B
//
// 이전 집의 색이 이번 선택에 영향을 주므로 그리디는 아님
// -> 이번의 최소 경로가 제한으로 인해 선택 불가능한 경우도 생김
//
// 이전의 최소 비용 합에서 이번 시도의 최소 비용을 다시 합치면 됨
// 모든 경우를 찾는데 비용이 최소가 되면 됨

inline constexpr int R = 0;
inline constexpr int G = 1;
inline constexpr int B = 2;

// N번째 집에서 R/G/B를 칠할 때 비용의 최솟값
inline int dp[1001][3];

// N번째 집에서 R/G/B로 칠할 때 비용
inline int cost[1001][3];

inline void solve()
{
	int n;
	cin >> n;

	for (int nn = 1; nn <= n; ++nn)
	{
		cin >> cost[nn][R] >> cost[nn][G] >> cost[nn][B];
	}

	// 1번째
	// -> 굳이 대입할 필요는 없겠지만 점화식을 생각해봤을때
	dp[1][R] = cost[1][R];
	dp[1][G] = cost[1][G];
	dp[1][B] = cost[1][B];

	// 점화식:
	// dp[i][R] = cost[i][R] + min(dp[i - 1][G], dp[i - 1][B]);
	// dp[i][G] = cost[i][G] + min(dp[i - 1][R], dp[i - 1][B]);
	// dp[i][B] = cost[i][B] + min(dp[i - 1][R], dp[i - 1][G]);

	for (int ii = 2; ii <= n; ++ii)
	{
		dp[ii][R] = cost[ii][R] + min(dp[ii - 1][G], dp[ii - 1][B]);
		dp[ii][G] = cost[ii][G] + min(dp[ii - 1][R], dp[ii - 1][B]);
		dp[ii][B] = cost[ii][B] + min(dp[ii - 1][R], dp[ii - 1][G]);
	}

	cout << min({dp[n][R], dp[n][G], dp[n][B]}) << '\n';
}
