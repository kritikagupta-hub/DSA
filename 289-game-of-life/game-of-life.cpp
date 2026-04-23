class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live = 0;
                for(int d=0;d<8;d++){
                    int nei = i+dx[d];
                    int nej = j+dy[d];

                    if(nei>=0 && nei<n && nej>=0 && nej<m){
                        if(board[nei][nej]==1 || board[nei][nej]==2){
                            live++;
                        }
                    }
                }

                if(board[i][j]==1){
                    if(live<2 || live>3){
                        board[i][j]=2;
                    }
                }
                else{
                    if(live==3){
                        board[i][j]=3;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }
                else if(board[i][j]==3){
                    board[i][j]=1;
                }
            }
        }
    }
};