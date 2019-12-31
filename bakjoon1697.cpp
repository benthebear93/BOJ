#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[100001];
int n, k;
int time = 0;

int bfs() {
	queue<int> q; 
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int size = q.size();
		
 		for (int i = 0; i < size; i++) {
			n = q.front();
			q.pop();
			if (n == k){
				return time;
			}
			if (n -1 >= 0 && visited[n - 1] == 0) {
				q.push(n - 1);
				visited[n - 1] = true;
			}
			if (n +1 < 100001 && visited[n + 1] == 0) {
				q.push(n + 1);
				visited[n + 1] = true;
			}
			if (n * 2 < 100001 && visited[n * 2] == 0) {
				q.push(n * 2);
				visited[n * 2] = true;
			}
		}
		time++;
	}
}

int main() {
	cin >> n >> k;
	time = bfs();
	cout << time << endl;
	return 0;
}
