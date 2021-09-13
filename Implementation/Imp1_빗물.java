package Implementation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Imp1_빗물 {

	public static void main(String[] args) throws IOException {
		/*
		 * 2021.09.13
		 * 김경아
		 * 백준 14719 빗물
		 * */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 입력값
		String[] input = br.readLine().split(" ");
		int h = Integer.parseInt(input[0]);
		int w = Integer.parseInt(input[1]);

		String[] temp = br.readLine().split(" ");
		int[] places = new int[temp.length];

		for (int i = 0; i < places.length; i++)
			places[i] = Integer.parseInt(temp[i]);

		// 정답 체크 변수
		int answer = 0;

		// 배열 인덱스. 0번째와 마지막은 검사하지않음
		for (int i = 1; i < w - 1; i++) {

			// 현재 칸에서 최대로 채울수있는 빗물의 양 부터 감소하며 검사
			for (int curH = h - places[i]; curH > 0; curH--) {
				// 현재 칸 기준 왼쪽, 오른쪽의 벽을 검사하여 최대로 채울수 있는 빗물의 양을 구한다
				boolean leftFlag = false;
				boolean rightFlag = false;

				// 왼쪽
				// 0번째 칸부터 현재 칸까지 검사하여
				// 현재 칸의 최대로 채워질수 있는 빗물보다 높거나 같은 벽이 있는지 검사
				for (int j = 0; j < i; j++) {
					if (curH + places[i] <= places[j]) {
						leftFlag = true;
						break;
					}
				}
				
				//이미 왼쪽에 현재 높이보다 높거나 같은 벽이 없다면 현재의 빗물(curH)는 채울수 없으니 오른쪽검사를 하지않기
				if (!leftFlag) 
					continue;
				
			
				// 오른쪽
				// 현재칸보다 오른쪽 칸부터 끝 칸까지 검사하여
				// 현재 칸의 최대로 채워질수 있는 빗물보다 높거나 같은 벽이 있는지 검사
				for (int j = i + 1; j < w; j++) {
					if (curH + places[i] <= places[j]) {
						rightFlag = true;
						break;
					}
				}

				// 왼쪽, 오른쪽 현재의 빗물(curH) 과 같거나 높은 벽이 있다면 답에 추가
				if (rightFlag) {
					answer += curH;
					break;
				}

			}

		}
		bw.append(String.valueOf(answer));
		bw.flush();
	}

}
