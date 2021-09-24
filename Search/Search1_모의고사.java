package Search;

import java.util.ArrayList;

public class Search1_모의고사 {

	public static void main(String[] args) {
		/*
		 * 2021.09.24 김경아 프로그래머스 모의고사
		 */

		//테스트 입력값
		int[] answers = { 1, 3, 2, 4, 2 };

		//수포자 답안
		int[] first = { 1, 2, 3, 4, 5 };
		int[] second = { 2, 1, 2, 3, 2, 4, 2, 5 };
		int[] third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

		ArrayList<Integer> maxArray = new ArrayList<Integer>();

		//각 수포자의 점수 저장 변수
		int a = 0;
		int b = 0;
		int c = 0;
		
		//맞은 갯수 체크
		for (int j = 0; j < answers.length; j++) {
			if (answers[j] == first[j % first.length]) a++;
			if (answers[j] == second[j % second.length]) b++;
			if (answers[j] == third[j % third.length]) c++;
		}

		//최고 득점자 판별해 maxArray에 추가
		int max = Math.max(Math.max(a, b), c);
		if (max == a) maxArray.add(1);
		if (max == b) maxArray.add(2);
		if (max == c) maxArray.add(3);

		//maxArray에 있는 수포자 array로 변환
		int[] an = new int[maxArray.size()];
		for (int i = 0; i < an.length; i++) 
			an[i] = maxArray.get(i);
		
		
		//return an;

	}

}
