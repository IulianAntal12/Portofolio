package graph.algorithmfactory;

import graph.components.Graph;
import graph.components.Vertex;

import java.util.Arrays;
import java.util.List;

public class MinimalColoringAlgorithm implements Algorithm {
    private final Graph graph;
    private final String root;

    public MinimalColoringAlgorithm(Graph graph, String root) {
        this.graph = graph;
        this.root = root;
    }

    @Override
    public String algorithm() {
        int verticesCount = graph.getVertexSet().size();
        int[] result = new int[verticesCount+1];
        Arrays.fill(result, -1);
        int rootValue=Integer.parseInt(root);
        result[rootValue] = 0;
        boolean[] available = new boolean[verticesCount+1];
        Arrays.fill(available, true);
        for (int iterator = 1; iterator <= verticesCount; iterator++) {
            if(iterator==rootValue)
                continue;
            else{
                List<Vertex> vertices = graph.getAdjVertices(String.valueOf(iterator));
                for (int iterator1 = 0; iterator1 < vertices.size(); iterator1++) {
                    if (result[Integer.parseInt(vertices.get(iterator1).getName())] != -1)
                        available[result[Integer.parseInt(vertices.get(iterator1).getName())]] = false;
                }
                int color;
                for (color = 1; color <= verticesCount; color++)
                    if (available[color])
                        break;
                result[iterator] = color;
                Arrays.fill(available, true);
            }

        }
        StringBuilder coloring = new StringBuilder();
        for (int iterator = 1; iterator <=verticesCount; iterator++)
            coloring.append(result[iterator]);
        return coloring.toString();
    }
}
