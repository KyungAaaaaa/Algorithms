package Implementation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Impl2_결혼식 {

	public static void main(String[] args) throws IOException {
		/*
		 * 2021.09.24 김경아 백준 5567 결혼식
		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());

		// 친구관계를 담을 2차원 배열 생성
		ArrayList<ArrayList<String>> fr = new ArrayList<ArrayList<String>>();

		// 초대할 친구를 담을 배열 생성
		ArrayList<String> invitation = new ArrayList<String>();

		// 친구관계를 fr 배열에 넣기
		for (int i = 0; i < m; i++) {
			ArrayList<String> temp = new ArrayList<String>();
			String[] st = br.readLine().split(" ");
			temp.add(st[0]);
			temp.add(st[1]);

			fr.add(temp);
		}

		// 상근이(1)의 친구를 찾아 초대할친구 배열(invitation)에 추가
		for (int i = 0; i < fr.size(); i++) {
			if (fr.get(i).contains("1")) {
				// 상근이 친구의 인덱스를 구별해 추가
				if (fr.get(i).indexOf("1") == 0)
					invitation.add(fr.get(i).get(1));
				else
					invitation.add(fr.get(i).get(0));
				// 구분했으니 친구 관계에서 삭제하고, 삭제하면 index가 당겨지기때문에 i감소
				fr.remove(i--);
			}
		}

		// 상근이의 친구가 배열에 담겨있으므로
		// 상근이 친구의 친구를 구분하기위해
		// 변수로 지정
		int frCt = invitation.size();

		// 상근이 친구를 기준으로 친구의 친구를 찾는다
		for (int j = 0; j < frCt; j++) {
			// 상근이의 친구
			String curFr = invitation.get(j);

			// 친구의 친구를 친구관계에서 찾아본다
			for (int i = 0; i < fr.size(); i++) {
				if (fr.get(i).contains(curFr)) {
					String frfr = "";
					// 친구의 친구 인덱스 찾기
					if (fr.get(i).indexOf(curFr) == 0)
						frfr = fr.get(i).get(1);
					else
						frfr = fr.get(i).get(0);

					// 이미 초대 배열에 추가 돼잇는지 검사
					if (!invitation.contains(frfr))
						invitation.add(frfr);
				}
			}
		}

		bw.append(String.valueOf(invitation.size()));
		bw.flush();
	}

}
