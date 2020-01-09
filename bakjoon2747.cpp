//bakjoon2747
#include <iostream>
#include <queue>

using namespace std;
int n;
double dp(int x){
	int ans[100];
	ans[0] = 0;
	ans[1] = 1;
	
	if(ans[x] != 0) return ans[n];
	if((n==0) || (n==1) ) return ans[n];
	return ans[n] = dp(n-1) + dp(n-2);
}

int main(){
	cin >> n;
	cout << dp(n);
}
