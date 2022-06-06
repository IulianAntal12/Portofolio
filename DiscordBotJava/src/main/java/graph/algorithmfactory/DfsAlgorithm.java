package graph.algorithmfactory;

import graph.components.Graph;
import graph.components.Vertex;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class DfsAlgorithm implements Algorithm {
    private final Graph graph;
    private final String root;

    public DfsAlgorithm(Graph graph, String root) {
        this.graph = graph;
        this.root = root;
    }

    @Override
    public String algorithm() {
        StringBuilder result = new StringBuilder();
        result.append("Dfs visiting order starting from vertex: ").append(root).append(" is: ");
        List<String> visited = new ArrayList<>();
        Stack<String> stack = new Stack<String>();
        stack.push(root);
        while (!stack.isEmpty()) {
            String vertex = stack.pop();
            if (!visited.contains(vertex)) {
                visited.add(vertex);
                for (Vertex v : graph.getAdjVertices(vertex)) {
                    stack.push(v.getName());
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
