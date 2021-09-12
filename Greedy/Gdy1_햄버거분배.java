package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Gdy1_ÇÜ¹ö°ÅºÐ¹è {

	public static void main(String[] args) throws IOException {

		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		String[] input = bw.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int k = Integer.parseInt(input[1]);

		char[] table = bw.readLine().toCharArray();

		int answer = 0;
		for (int i = 0; i < n; i++) {
			if (table[i] == 'P') {
				int cur = i - k < 0 ? 0 : i - k;
				int max = i + k >= n ? n - 1 : i + k;

				while (cur <= max) {
					if (table[cur] == 'H') {
						table[cur] = 'X';
						answer++;
						break;
					} else
						cur++;
				}
			}
		}
		System.out.print(answer);

//		for (char c : table) {
//			System.out.print(c);
//		}
	}

}
