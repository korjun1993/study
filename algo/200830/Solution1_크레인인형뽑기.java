package level1;

import java.util.Stack;

public class Solution1_크레인인형뽑기 {
	
	public int solution(int[][] board, int[] moves) {
		int answer = 0;
		
		Stack<Integer> s = new Stack<Integer>();
		
		for(int i = 0; i < moves.length; i++) {			
			int c = moves[i] - 1;
			
			for(int j = 0; j < board.length; j++) {
				if(board[j][c] == 0)
					continue;
				
				if(!s.isEmpty() && s.peek() == board[j][c]) {
					s.pop();
					answer += 2;
				}
				
				else {
					s.push(board[j][c]);
				}
				
				board[j][c] = 0;
			}
		}
		
		return answer;
	}
}