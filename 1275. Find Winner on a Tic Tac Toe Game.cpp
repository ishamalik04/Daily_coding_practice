1275. Find Winner on a Tic Tac Toe Game
Easy
1.2K
297
Companies
Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.



Example 1:


Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
Example 2:


Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.


solution

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int row[2][3]={},col[2][3]={},d1[2]={},d2[2]={},id=0;
        for(auto i:moves){
                if(++row[id][i[0]]==3 || ++col[id][i[1]]==3 ||  i[0]==i[1] && ++d1[id]==3 || i[0]+i[1]==2 && ++d2[id]==3)
                    return id==0?"A":"B";
            id=id==0?1:0;
            }
        return moves.size()==9?"Draw":"Pending";
    }
};
