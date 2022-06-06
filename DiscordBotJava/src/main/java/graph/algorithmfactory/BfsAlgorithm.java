package graph.algorithmfactory;

import graph.components.Graph;
import graph.components.Vertex;

import java.util.*;

public class BfsAlgorithm implements Algorithm {
    private final Graph graph;
    private final String root;

    public BfsAlgorithm(Graph graph, String root) {
        this.graph = graph;
        this.root = root;
    }

    @Override
    public String algorithm() {
        StringBuilder result = new StringBuilder();
        result.append("Bfs visiting order starting from vertex: ").append(root).append(" is: ");
        List<String> visited = new ArrayList<>();
        Queue<String> queue = new LinkedList<String>();
        queue.add(root);
        visited.add(root);
        while (!queue.isEmpty()) {
            String vertex = queue.poll();
            for (Vertex v : graph.getAdjVertices(vertex)) {
                if (!visited.contains(v.getName())) {
                    visited.add(v.getName());
                    queue.add(v.getName());
                }
            }
        }
        result.append("(");
        for (int iterator = 0; iterator < visited.size() - 1; iterator++)
            result.append(visited.get(iterator)).append(",");
        int iterator = visited.size();
        result.append(visited.get(iterator - 1));
        result.append(")");
        return result.toString();
    }
}
