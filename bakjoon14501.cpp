//bakjoon 14501

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int n;
int t, p;
queue <pair <int, int> > q;
queue <pair <int, int> > q_copy;
priority_queue <int> p_q;

int solver(int a){
	int ans = 0;
	int total_day = 1;
	int day = q.front().first;
	int time = q.front().second;
	q.pop();
	int temp =0;
	while(a <= n){

		if(a == total_day){
			temp = total_day;
			total_day = total_day+ day;
			a = a+ day;
			if(total_day <= n){
				ans = ans + time;
				day = q.front().first;
				time = q.front().second;
				q.pop();
			}
			else{
				day = q.front().first;
				time = q.front().second;
				q.pop();
				total_day = temp;
			}
		}
		else{
			q.pop();
			a++;
		}
	}
	return ans;
}


int main(){
	cin >> n;
	int res = 0;
	for(int i=0; i<n; i++){
		cin >> t >> p;
		q.push(make_pair(t, p));
	}
	q_copy = q;
	for(int i = 1; i <=n ;i ++){
		res = solver(i);
		p_q.push(res);
		q = q_copy;
		q.pop();
	}
	cout << p_q.top() << endl;
	
}
