package graph.algorithmfactory;

import exceptions.InvalidAlgorithmException;
import graph.components.Graph;
import graph.components.Vertex;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class AlgorithmFactory {

    public boolean connected(Graph graph) {
        List<String> visited = new ArrayList<>();
        Stack<String> stack = new Stack<>();
        stack.push(String.valueOf(1));
        while (!stack.isEmpty()) {
            String vertex = stack.pop();
            if (!visited.contains(vertex)) {
                visited.add(vertex);
                for (Vertex v : graph.getAdjVertices(vertex)) {
                    stack.push(v.getName());
                }
            }
        }
        return visited.size() == graph.getVertexSet().size();
    }

    public Algorithm createAlgorithm(String algorithm, Graph graph, String root) throws InvalidAlgorithmException {
        if (algorithm.isEmpty())
            return null;
        switch (algorithm) {
            case "Bfs" -> {
                if (!connected(graph))
                    throw new InvalidAlgorithmException("You need a connected graph!");
                else
                    return new BfsAlgorithm(graph, root);
            }
            case "Dfs" -> {
                if (!connected(graph))
                    throw new InvalidAlgorithmException("You need a connected graph!");
                else
                    return new DfsAlgorithm(graph, root);
            }
            case "MinimalColoring" -> {
                return new MinimalColoringAlgorithm(graph,root);
            }
            default -> throw new InvalidAlgorithmException("I don't know this algorithm or it doesn't exist :(");
        }
    }
}
