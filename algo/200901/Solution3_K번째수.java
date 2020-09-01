package level1;

public class Solution3_K번째수 {
	public int[] solution(int[] array, int[][] commands) {
		int[] answer = new int[commands.length];
		int[] arr;
		int num;

		for (int i = 0; i < commands.length; i++) {
			num = 0;
			arr = new int[commands[i][1] - commands[i][0] + 1];

			for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
				arr[num++] = array[j];
			}

			// bSort(arr);
			// iSort(arr);
			// sSort(arr);
			// qSort(arr);
			answer[i] = arr[commands[i][2]];
		}

		return answer;
	}

	// 버블 정렬
	private void bSort(int[] arr) {
		int tmp = 0;
		for (int i = 1; i < arr.length; i++) {
			for (int j = 0; j < arr.length - i; j++) {
				if (arr[j] > arr[j + 1]) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}

	}

	// 삽입정렬
	private void iSort(int[] arr) {
		int min, idx;

		for (int i = 1; i < arr.length; i++) {
			min = arr[i];
			idx = i - 1;
			while (idx >= 0 && min < arr[idx]) {
				arr[idx + 1] = arr[idx];
				idx--;
			}
			arr[idx + 1] = min;
		}
	}

	// 선택정렬
	private void sSort(int[] arr) {
		int minIdx, tmp;

		for (int i = 0; i < arr.length - 1; i++) {
			minIdx = i;
			for (int j = i + 1; j < arr.length; j++) {
				if (arr[minIdx] > arr[j]) {
					minIdx = j;
				}
			}
			tmp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = tmp;
		}
	}

	// 퀵소트
	private void qSort(int[] arr) {
		
	}
}
