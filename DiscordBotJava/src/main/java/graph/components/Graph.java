package graph.components;

import exceptions.InvalidGraphException;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.*;

@Data
@NoArgsConstructor
public class Graph {
    private final List<Edge> edgeList = new ArrayList<>();
    private final Set<Vertex> vertexSet = new HashSet<>();

    public Graph(String verticesCount, String edges) throws InvalidGraphException {
        createEdges(edges, verticesCount);
    }

    private void addEdge(Edge edge) {
        edgeList.add(edge);
    }

    private void addVertex(Vertex vertex) {
        vertexSet.add(vertex);
    }

    private void createEdges(String edgeList, String vertices) throws InvalidGraphException {
        String[] edges = edgeList.split("-");
        if (edges.length % 2 == 1) {
            throw new InvalidGraphException("Enter an even number of edges!");
        } else if (Integer.parseInt(vertices) < 1) {
            throw new InvalidGraphException("You can't have a negative number of vertices!");
        } else {
            createVertices(vertices);
            for (int iterator = 0; iterator < edges.length - 1; iterator += 2) {
                Vertex sourceVertex = findVertex(edges[iterator]);
                Vertex destinationVertex = findVertex(edges[iterator + 1]);
                if (sourceVertex == null || destinationVertex == null)
                    throw new InvalidGraphException("Invalid vertex.");
                else if (sourceVertex.equals(destinationVertex)) {
                    throw new InvalidGraphException("You can't have edge between same vertex!");
                } else {
                    Edge edge = new Edge(sourceVertex, destinationVertex);
                    addEdge(edge);
                }
            }
        }
    }

    private Vertex findVertex(String edge) {
        for (Vertex vertex : vertexSet)
            if (vertex.getName().equals(edge))
                return vertex;
        return null;
    }

    private void createVertices(String verticesCount) {
        int count = Integer.parseInt(verticesCount);
        for (int iterator = 1; iterator <= count; ++iterator) {
            Vertex vertex = new Vertex(100 * iterator, 100 * iterator, String.valueOf(iterator));
            addVertex(vertex);
        }
    }

    public List<Vertex> getAdjVertices(String vertex) {
        List<Vertex> vertices = new ArrayList<>();
        for (Edge edge : edgeList) {
            if (edge.getDestinationVertex().getName().equals(vertex)) {
                vertices.add(edge.getSourceVertex());
            } else if (edge.getSourceVertex().getName().equals(vertex)) {
                vertices.add(edge.getDestinationVertex());
            }
        }
        return vertices;
    }

    @Override
    public String toString() {
        return "Graph{" +
                "edgeList=" + edgeList +
                ", vertexSet=" + vertexSet +
                '}';
    }

}
