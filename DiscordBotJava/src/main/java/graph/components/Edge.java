package graph.components;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class Edge {
    private Vertex sourceVertex;
    private Vertex destinationVertex;
    private int sourceValue;
    private int destinationValue;

    public Edge(Vertex sourceVertex, Vertex destinationVertex) {
        this.sourceVertex = sourceVertex;
        this.destinationVertex = destinationVertex;
        this.sourceValue = Integer.parseInt(sourceVertex.getName());
        this.destinationValue = Integer.parseInt(destinationVertex.getName());
    }

    @Override
    public String toString() {
        return "(" + sourceVertex + "," + destinationVertex + ")";
    }
}

