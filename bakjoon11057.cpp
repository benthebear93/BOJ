#include <iostream>
using namespace std;
int ans;
int dp[1001][10];
const int divd = 10007;
int a;
int solver(){
	for(int i = 0; i <=9; i++)dp[1][i] = 1; //when input = 1
		
	for(int i = 2; i <= a; i ++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <=j; k++){
				dp[i][j] +=dp[i-1][k]; // dp[2][0] = dp[1][0], dp[2][9] = dp[1][0]+ dp[1][1] + dp[1][2] + dp[1][3] ~ + dp[1][9]
			}
			dp[i][j] %=divd;
		}
	}
	for(int i = 0; i <=9; i++) ans +=dp[a][i];
	printf("%d\n", ans%divd);
}
int main(){
	scanf("%d", &a);
	solver();
	 
}
