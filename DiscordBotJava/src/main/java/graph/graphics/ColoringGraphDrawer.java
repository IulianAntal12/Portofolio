package graph.graphics;

import graph.components.Edge;
import graph.components.Vertex;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class ColoringGraphDrawer extends JFrame {
    private Graphics graphics;
    private final int width;
    private final int height;
    private ArrayList<Edge> edgeList;
    private ArrayList<Vertex> vertexList;
    private final int[] coloring;

    public ColoringGraphDrawer(int[] coloring) {
        edgeList = new ArrayList<>();
        vertexList = new ArrayList<>();
        width = 30;
        height = 30;
        this.coloring = coloring;
    }

    public void addNode(String name, int coordX, int coordY) {
        vertexList.add(new Vertex(coordX, coordY, name));
        this.repaint();
    }

    public void addEdge(Vertex sourceVertex, Vertex destinationVertex) {
        edgeList.add(new Edge(sourceVertex, destinationVertex));
        this.repaint();
    }

    @Override
    public void paint(Graphics graphics) { //draw the nodes and edges
        FontMetrics font = graphics.getFontMetrics();
        int nodeHeight = Math.max(height, font.getHeight());
        graphics.setColor(Color.black);

        for (Edge e : edgeList) {
            graphics.drawLine(vertexList.get(e.getSourceValue() - 1).getXCoord(),
                    vertexList.get(e.getSourceValue() - 1).getYCoord(),
                    vertexList.get(e.getDestinationValue() - 1).getXCoord(),
                    vertexList.get(e.getDestinationValue() - 1).getYCoord());
        }

        for (int i = 0; i < vertexList.size(); i++) {
            Vertex n = vertexList.get(i);
            int nodeWidth = Math.max(width, font.stringWidth(n.getName()) + width / 2);

            switch (coloring[i]) {
                case 0 -> graphics.setColor(Color.BLUE);
                case 1 -> graphics.setColor(Color.red);
                case 2 -> graphics.setColor(Color.GREEN);
                case 3 -> graphics.setColor(Color.ORANGE);
                default -> graphics.setColor(Color.white);
            }
            graphics.fillOval(n.getXCoord() - nodeWidth / 2, n.getYCoord() - nodeHeight / 2, nodeWidth, nodeHeight);
            graphics.setColor(Color.black);
            graphics.drawOval(n.getXCoord() - nodeWidth / 2, n.getYCoord() - nodeHeight / 2, nodeWidth, nodeHeight);
            graphics.drawString(n.getName(), n.getXCoord() - font.stringWidth(n.getName()) / 2, n.getYCoord() + font.getHeight() / 2);
        }
        this.graphics = graphics;
    }

    @Override
    public Graphics getGraphics() {
        return graphics;
    }
}