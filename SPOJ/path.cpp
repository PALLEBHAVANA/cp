#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include <utility> // you need this for make_pair. 

using namespace std;

int dfs(int i, int j, pair<int, vector<pair<int, int>>> **adj, int **max_table){
    int maxi = 1;
    for(pair<int, int> a: adj[i][j].second){
    	int k = max_table[a.first][a.second];
    	if( k == -1){
    		k = dfs(a.first, a.second, adj, max_table);
    		max_table[a.first][a.second] = k;
    	}
        maxi = max(maxi, 1+ k );
    }
    return maxi;
}

int main(){
    int t= 0;
    while(1){
        int n;
        int m;
        cin >> n >> m;
        t++;
        if( n == 0 && m == 0){
            break;
        }
        // initialize this way for sending double array to the function.
        pair<int,vector<pair<int, int>>> **adj;
        adj = new pair<int,vector<pair<int, int>>> *[n];
        for(int i=0; i<n; i++){
            adj[i] = new pair<int,vector<pair<int, int>>>[m];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char c;
                cin >> c;
                int in = c-'0';
                pair<int, vector<pair<int, int>>> p;
                p.first = in;
                p.second = {};
                adj[i][j] = p;    
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( i-1 >= 0){
                    if( j-1 >= 0 && adj[i-1][j-1].first == adj[i][j].first + 1){
                        adj[i][j].second.push_back(make_pair(i-1, j-1));
                    }
                    if( j+1 < m && adj[i-1][j+1].first == adj[i][j].first + 1){
                        adj[i][j].second.push_back(make_pair(i-1, j+1));
                    }
                    if( adj[i-1][j].first == adj[i][j].first + 1) {
                        adj[i][j].second.push_back(make_pair(i-1, j));
                    }
                }
                if( i+1 < n){
                    if( j-1 >= 0 && adj[i+1][j-1].first == adj[i][j].first + 1){
                        adj[i][j].second.push_back(make_pair(i+1, j-1));
                    }
                    if( j+1 < m && adj[i+1][j+1].first == adj[i][j].first + 1){
                        adj[i][j].second.push_back(make_pair(i+1, j+1));
                    }
                    if( adj[i+1][j].first == adj[i][j].first + 1){
                        adj[i][j].second.push_back(make_pair(i+1, j));    
                    }
                }
                if( j -1 >= 0){
                    if( adj[i][j-1].first == adj[i][j].first + 1 ){
                        adj[i][j].second.push_back(make_pair(i, j-1));    
                    }
                }
                if( j+1 < m){
                    if( adj[i][j+1].first == adj[i][j].first + 1){
                        adj[i][j].second.push_back(make_pair(i, j+1));
                    }
                }
            }    
        }
        int maxi = 0;
        int** max_table;
        max_table = new int*[n];
        for(int i=0; i<n; i++){
        	max_table[i] = new int[m];
        	for(int j=0; j<m; j++){
        		max_table[i][j] = -1;
        	}
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( adj[i][j].first == 17){
                    maxi = max(maxi, dfs(i, j, adj, max_table));
                }
            }
        }
        cout << "Case " << t << ": " << maxi << endl;
        
        // Free the allocated memory
        for (int i = 0; i < n; i++) {
            delete[] adj[i];
            delete[] max_table[i];
        }
        delete[] adj;
        delete[] max_table;
    }
    return 0;
}

