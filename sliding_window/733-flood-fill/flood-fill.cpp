class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& graph, int sr, int sc, int color) {
    queue<pair<int, int>> q;
    

    int max_row = graph.size();
    int max_col = graph[0].size();
    //vector<int> visited(max_row*max_col , flase);

    int key = graph[sr][sc];
    q.push(make_pair(sr, sc));

    while (!q.empty()) {
      pair<int, int> cell = q.front();
      //visited[cell]
      q.pop();

      int row = cell.first;
      int col = cell.second;

      if (graph[row][col] == key) { // Only check for the initial key color
        graph[row][col] = color;
        cout<< "row :"<< row << " col "<< col << endl;

        for (int i = 0; i < 2; i++) {
          int temp1 = i % 2;
          int temp2 = (i + 1) % 2;

          if (row + temp1 < max_row && col + temp2 < max_col && graph[row + temp1][col + temp2] == key) {
            if( graph[row + temp1][col + temp2] == color){
                continue;
            }
            cout<< "pushed: "<< row+temp1 << " "<< col+temp2<< endl;  
            q.push(make_pair(row + temp1, col + temp2));
          }
          if (row - temp1 >= 0 && col - temp2 >= 0 && graph[row - temp1][col - temp2] == key) {
            if(graph[row-temp1][col-temp2] == color){
                continue;
            }
            cout<< "pushed  : "<< row-temp1 << " , "<< col-temp2 << endl; 
            q.push(make_pair(row - temp1, col - temp2));
          }
        }
      }
    }

    return graph;
  }
};
