#include <iostream>
#include <queue>

using namespace std;
int f,s,g,u,d;
//f : building floor#
//s : current_floor
//g : destination
//u : up, d : down 
int check;
int visited[1000000];
int time;
int bfs(){
	queue <int> q;
	q.push(s);
	visited[s] = true;
	
	while(!q.empty()){
		int size = q.size();
		
		for(int i = 0; i<size ; i++){
			s = q.front();
			q.pop();
			
			if(s == g){
				return time;
			}
			if(s+u <=f && visited[s+u]==0){
				q.push(s+u);
				visited[s+u] = 1;
			}
			if(s-d <f && s-d>0&& visited[s-d]==0){
				q.push(s-d);
				visited[s-d] = 1;
			}
		}
		time ++;
	}
	if(time > f || s!=g){
		time = -1;
		return time;
	}
}

int main(){
	cin >>f >> s>> g >> u >> d;
	time=bfs();
	if(time == -1){
		cout <<"use the stairs"<<endl;
	}
	else{
		cout << time << endl;
	}
}
