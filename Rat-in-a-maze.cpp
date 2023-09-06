// 6 september 2023
//Rat in a maze
// GFG


/*Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.*/

class Solution{
    public:
    bool isSafe(int i, int j, int row, int col, vector<vector<int>> &arr,vector<vector<bool> > &visited) 
    {
        if( ((i>=0 && i < row) && (j >= 0 && j< col)) &&(arr[i][j] == 1 ) &&(visited[i][j]==false)) 
        {
            return true;
        }
        else {
            return false;
        }
    }
    
    
    void solveMaze(vector<vector<int>> &arr, int row,int col, int i, int j,vector<vector<bool> > &visited, vector<string>& path, string output) 
    {
        //base case
        if(i == row-1 && j == col-1) {
        //answer found
            path.push_back(output);
            return;
        } 

        //Down -> i+1, j
        if(isSafe(i+1, j, row, col, arr, visited)) {
            visited[i+1][j] = true;
            solveMaze(arr, row, col, i+1, j, visited, path, output + 'D');
            //backtrack 
            visited[i+1][j] = false;
        }

  //Left -> i, j-1
        if(isSafe(i, j-1, row, col, arr, visited)) {
            visited[i][j-1] = true;
            solveMaze(arr, row, col, i, j-1, visited, path, output + 'L');
            //backtrack 
            visited[i][j-1] = false;
        }

  //Right -> i, j+1
        if(isSafe(i, j+1, row, col, arr, visited)) {
            visited[i][j+1] = true;
            solveMaze(arr, row, col, i, j+1, visited, path, output + 'R');
            //backtrack 
            visited[i][j+1] = false;
        }

  //Up-> i-1, j
        if(isSafe(i-1, j, row, col, arr, visited)) {
            visited[i-1][j] = true;
            solveMaze(arr, row, col, i-1, j, visited, path, output + 'U');
            //backtrack 
            visited[i-1][j] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        int row = n;
        int col = n;
        vector<vector<bool> > visited(row, vector<bool>(col,false));
         //src ki value k true mark kredete h 
        visited[0][0] = true;
        vector<string> path;
        string output = "";
        if(m[0][0] == 0) {
            return path;
        }
        solveMaze(m,row,col, 0,0, visited, path, output);
        return path;
    }
        
};
