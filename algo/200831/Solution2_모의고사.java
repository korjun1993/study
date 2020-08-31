package level1;

import java.util.ArrayList;
import java.util.List;

public class Solution2_모의고사 {
	public int[] solution(int[] answers) {
		int[] answer = { 0, 0, 0 };

		int[] n1 = { 1, 2, 3, 4, 5 };
		int[] n2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
		int[] n3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

		for (int i = 0; i < answers.length; i++) {
			if (answers[i] == n1[i % 5])
				answer[0]++;
			if (answers[i] == n2[i % 8])
				answer[1]++;
			if (answers[i] == n3[i % 10])
				answer[2]++;
		}

		int max = Integer.MIN_VALUE;

		for (int i = 0; i < answer.length; i++) {
			if (max < answer[i])
				max = answer[i];
		}

		List<Integer> list = new ArrayList<Integer>();

		for (int i = 0; i < answer.length; i++) {
			if (max == answer[i]) {
				list.add(i + 1);
			}
		}

		answer = new int[list.size()];
		
		for (int i = 0; i < answer.length; i++) {
			answer[i] = list.get(i);
		}
		
		return answer;
	}
}
