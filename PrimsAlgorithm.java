package bst;

import java.util.Arrays;

public class PrimsAlgorithm {
	public static void main(String[] args) {
		int[][] graph = {
				{0, 2, 0, 6, 0},
				{2, 0, 3, 8, 5},
				{0, 3, 0, 0, 7},
				{6, 8, 0, 0, 9},
				{0, 5, 7, 9, 0}
		};
		primMST(graph);
	}

	public static void primMST(int[][] graph) {
		int numVertices = graph.length;
		int[] parent = new int[numVertices];
		int[] minWeight = new int[numVertices];
		boolean[] includedInMST = new boolean[numVertices];

		Arrays.fill(minWeight, Integer.MAX_VALUE);
		minWeight[0] = 0		parent[0] = -1;

		for (int count = 0; count < numVertices - 1; count++) {
			int minWeightVertex = getMinWeightVertex(minWeight, includedInMST);
			includedInMST[minWeightVertex] = true;

			for (int vertex = 0; vertex < numVertices; vertex++) {
				if (graph[minWeightVertex][vertex] != 0 && !includedInMST[vertex] && graph[minWeightVertex][vertex] < minWeight[vertex]) {
					parent[vertex] = minWeightVertex;
					minWeight[vertex] = graph[minWeightVertex][vertex];
				}
			}
		}

		System.out.println("Edge \tWeight");
		for (int i = 1; i < numVertices; i++) {
			System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
		}
	}

	public static int getMinWeightVertex(int[] minWeight, boolean[] includedInMST) {
		int minWeightValue = Integer.MAX_VALUE;
		int minWeightVertex = -1;
		for (int vertex = 0; vertex < minWeight.length; vertex++) {
			if (!includedInMST[vertex] && minWeight[vertex] < minWeightValue) {
				minWeightValue = minWeight[vertex];
				minWeightVertex = vertex;
			}
		}
		return minWeightVertex;
	}
}
