package graph.components;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class Vertex {
    private int xCoord;
    private int yCoord;
    private String name;

    public Vertex(int xCoord, int yCoord, String name) {
        this.xCoord = xCoord;
        this.yCoord = yCoord;
        this.name = name;
    }

    @Override
    public String toString() {
        return this.name;
    }
}
