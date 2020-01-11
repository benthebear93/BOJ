//bakjoon1463
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;
int ans[1000001];
int result;

void dp(int n){
	for(int i = 2; i<=n; i++){
		ans[i] = ans[i-1]+1;
		if( i % 2 == 0) ans[i] = min(ans[i], ans[i/2]+1);
		if( i % 3 == 0) ans[i] = min(ans[i], ans[i/3]+1);
	}
}

int main(){
	cin >> n;
	ans[0] = 0;
	ans[1] = 0;
	dp(n);
	result = ans[n];
	cout << result;
}
