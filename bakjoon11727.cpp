#include <iostream>

using namespace std;
int dp[1001] = {0,1,3};

int dp_f(int n){
	if(dp[n]!=0) return dp[n];
	return dp[n] = (dp_f(n-1) % 10007 + 2* dp_f(n-2) % 10007) % 10007;
}

int main(){
	int n;
	cin>> n ;
	cout << dp_f(n) << endl;
}
