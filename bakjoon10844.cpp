#include <iostream>
#define mod 1000000000
using namespace std;
int n;
long ans;
/// 1<= n <= 100
long dp[101][10];

void solver(){
	for(int i = 0; i < 10; i++)dp[1][i] = 1; 
	
	for(int i = 2; i <= n; i++ ){
		for(int j = 0; j< 10; j++){
			if(j == 0) dp[i][0] = dp[i-1][j+1] % mod;
			else if(j == 9) dp[i][9] = dp[i-1][j-1] % mod;
			else{
				dp[i][j] +=dp[i-1][j-1] % mod;
				dp[i][j] +=dp[i-1][j+1] % mod;	
			}	
		}
	}
	
	for(int i = 1; i < 10; i++){
		ans +=dp[n][i];
	}
	cout<<ans % mod << endl;;
	
}
int main(){
	scanf("%d", &n);
	solver();
}
