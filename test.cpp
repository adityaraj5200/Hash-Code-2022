class Solution {
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int> > Q;
    vector<vector<int>> dis(n, vector<int>(m, -1));
    dis[start[0]][start[1]] = 0;
    Q.push({start[0], start[1]});
    int dx[4] = {0, 0, -1, 1};
    int dy[4] ={1, -1, 0, 0};
      
      // BFS
    while (!Q.empty()){
      auto [x,y] = Q.front();
      Q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny] != 0 and dis[nx][ny] == -1){
          dis[nx][ny] = 1 + dis[x][y];
          Q.push({nx, ny});
        }
      }
    }
      
    vector<vector<int>> answers;
    for(int i = 0; i < n ; i++){
      for(int j = 0; j < m ; j++){
        if(grid[i][j] >= pricing[0] and grid[i][j] <= pricing[1] and dis[i][j] != -1){
          // vector<int> v = {i, j,grid[i][j],dis[i][j]};
          // answers.push_back(v);
            vector<int> v = {dis[i][j],grid[i][j],i,j};
            answers.push_back(v); 
        }
      }
    }
      
    // Sort according to given conditions
      sort(begin(answers), end(answers));
//     sort(begin(answers), end(answers), [&](vector<int>&a, vector<int>&b){
        
//         // if distnces equal
//       if(a[3] == b[3]){
//           // distance and price equal
//         if(a[2] == b[2]){
//             // distance and price and row number equal
//           if(a[0] == b[0]) {
//             return a[1] < b[1];
//           }
//             //distance, price, row and colum number equal
//           return a[0] < b[0];
//         }
//         return a[2] < b[2];
//       }
//       return a[3] < b[3];
//     });
    vector<vector<int>> ans;
      
      // take first K elements from answers in ans
    for(int i = 0; i < answers.size() and k ; i++){
      ans.push_back({answers[i][2], answers[i][3]});
      k--;
    }
    return ans;
  }
};