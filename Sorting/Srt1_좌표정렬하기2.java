package Sorting;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Srt1_좌표정렬하기2 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int count = Integer.parseInt(br.readLine());
		int[][] position = new int[count][2];
		for (int i = 0; i < count; i++) {
			String[] temp = br.readLine().split(" ");
			position[i][0] = Integer.parseInt(temp[0]);
			position[i][1] = Integer.parseInt(temp[1]);
		}

		Arrays.sort(position, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[1] == o2[1])
					return o1[0] - o2[0];
				else
					return o1[1] - o2[1];
			}
		});

		for (int[] strings : position) {
			bw.append(strings[0] + " " + strings[1] + "\n");
		}
		bw.flush();
	}

}
