#include<iostream>
#include <utility> // remember this is the package for the pair.
#include <vector>
#include <queue>
using namespace std;

void bfs(int x1, int y1, int x2, int y2, vector<pair<int, int>> adj[][8]){
		bool used[8][8] = {false};
		used[x1][y1] = true;
		queue<pair<int, int>> q;   // empty queue;
		q.push(make_pair(x1, y1)); // push the source node s
		int d[8][8] = {-1};
		d[x1][y1] = 0;
		while(!q.empty()){
			pair<int, int> u = q.front();
			q.pop();
			for(pair<int, int> v : adj[u.first][u.second] ){
				if(!used[v.first][v.second]){
					q.push(v);
					used[v.first][v.second] = true;
					d[v.first][v.second] = d[u.first][u.second] + 1;
					if( v.first == x2 && v.second == y2 ){
						cout << d[v.first][v.second] << endl;
						return;
					}
				}
			}
		}
		cout << d[x2][y2] << endl;
		return;
}
int main(){
	int t;
	cin >> t;
	vector<pair<int, int>> adj[8][8];
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if( j+ 2 < 8){
				if( i+ 1 < 8 ){
					adj[i][j].push_back(make_pair(i+1, j+2));
				}
				if( i-1 >= 0){
					adj[i][j].push_back(make_pair(i-1, j+2));
				}
			}
			if( j - 2 >= 0){
				if( i+ 1 < 8 ){
					adj[i][j].push_back(make_pair(i+1, j-2));
				}
				if( i-1 >= 0){
					adj[i][j].push_back(make_pair(i-1, j-2));
				}
			}
			if( i+2 < 8){
				if( j+ 1 < 8){
					adj[i][j].push_back(make_pair(i+2, j+1));
				}
				if( j -1 >= 0){
					adj[i][j].push_back(make_pair(i+2, j-1));
				}
			}
			if( i - 2 >= 0){
				if( j+ 1 < 8){
					adj[i][j].push_back(make_pair(i-2, j+1));
				}
				if( j -1 >= 0){
					adj[i][j].push_back(make_pair(i-2, j-1));
				}
			}
		}
	}
	for(int i=0; i<t; i++){
		int x1, y1;
		int x2, y2;
		string s1, s2;
		cin >> s1 >> s2;
		x1 =  s1[0] - 'a';
		y1 = s1[1] - '1';
		x2 =  s2[0] - 'a';
		y2 = s2[1] - '1';
		bfs(x1, y1, x2, y2, adj);	
	}
}
