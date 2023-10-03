//2038. Remove Colored Pieces if Both Neighbors are the Same Color

//Lc 2038

/*There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
Alice and Bob cannot remove pieces from the edge of the line.
If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.

*/




class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceScore = 0, bobScore = 0; 

        for (int i = 1; i < colors.size() - 1; i++) {
            char currentColor = colors[i];
            char prevColor = colors[i - 1];
            char nextColor = colors[i + 1];

            if (currentColor == 'A' && prevColor == 'A' && nextColor == 'A')
                aliceScore++; 

            else if (currentColor == 'B' && prevColor == 'B' && nextColor =='B')
                bobScore++; 
        }

        return aliceScore > bobScore;
    }
    
};
