package discordbots;

import commands.Command;
import commands.CommandRepository;
import database.EntityManagerSingleton;
import discord4j.core.DiscordClient;
import discord4j.core.GatewayDiscordClient;
import discord4j.core.event.domain.lifecycle.ReadyEvent;
import discord4j.core.event.domain.message.MessageCreateEvent;
import discord4j.core.object.entity.Message;
import discord4j.core.object.entity.User;
import discord4j.core.spec.EmbedCreateSpec;
import exceptions.InvalidAlgorithmException;
import exceptions.InvalidGraphException;
import graph.algorithmfactory.Algorithm;
import graph.algorithmfactory.AlgorithmFactory;
import graph.components.Graph;
import graph.graphics.ColoringGraphDrawer;
import graph.graphics.GraphDrawer;
import org.checkerframework.checker.units.qual.C;
import reactor.core.publisher.Mono;

import javax.imageio.ImageIO;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.time.Instant;
import java.util.Random;

public class GraphBot {
    private static final int WIDTH = 500;
    private static final int HEIGHT = 500;

    private void createCommands() {
        Command command1 = new Command(2, "!graf", "Definiție: Se numește graf neorientat o pereche ordonată de mulțimi G=(X,U), unde:\n" +
                "-> X este o mulțime finită și nevidă de elemente numite vârfuri sau noduri;\n" +
                "-> U este o mulțime finită de submulțimi cu două elemente din X, numite muchii.");
        Command command2 = new Command(3, "!adiacenta", "Două vârfuri între care există muchie se numesc adiacente.");
        Command command3 = new Command(4, "!incidenta", "Două muchii sunt incidente dacă au o o extremitate comună. Un vârf este incident cu o muchie dacă vârful este extremitate a acelei muchii.");
        Command command4 = new Command(5, "!grad", "Definiție: Într-un graf neorientat se numește grad al unui vârf numărul de vârful adiacente cu acesta (sau numărul de muchii incidente cu acesta). Gradul unui vărf x se notează d(x) (degree).\n" +
                "\n" +
                "Observații:\n" +
                "\n" +
                "-> un vârf cu gradul 0 se numește izolat. În graful de mai sus, vârful 6 este izolat.\n" +
                "-> un vârf cu gradul 1 se numește terminal. În graful de mai sus, vârful 9 este vârf terminal.\n" +
                "->gradul maxim al unui vârf într-un graf cu n vârfuri este n-1.\n" +
                "\n" +
                "Teoremă: Într-un graf neorientat, suma gradelor tuturor vârfurilor este dublul numărului de muchii.");
        Command command5 = new Command(6, "!matriceDeAdiacenta", "Matricea de adiacență\n" +
                "Pentru un graf neorientat G=(X,U) cu n vârfuri, matricea de adiacență este o matrice cu n linii și n coloane și elemente din {0,1}, cu: \n Ai,j={1,dacă [i,j]∈U si 0, dacă [i,j]∉U" +
                "\n" +
                "Observații:\n" +
                "\n" +
                "-> matricea de adiacență este simetrică față de diagonala principală;\n" +
                "-> elementele de pe diagonala principală sunt 0;\n" +
                "-> gradul unui vârf x este egal cu numărul de elemente 1 de pe linia (sau coloana) x;\n" +
                "-> suma tuturor elementelor din matricea de adiacență a unui graf neorientat este egală cu dublul numărului de muchii din graf.\n");
        Command command6=new Command(7,"!listaDeMuchii","Lista de muchii a unui graf neorientat reprezintă o mulțime ce conține toate muchiile din graf.\n" +
                "\n" +
                "Pentru reprezentarea în memorie putem folosi:\n" +
                "\n" +
                "-> un tablou unidimensional cu elemente de tip struct {int I,J;}\n" +
                "-> două tablouri unidimensionale cu elemente de tip int\n" +
                "-> o listă alocată dinamic");
        Command command7=new Command(8,"!listaDeAdiacenta","Pentru un graf neorientat cu G=(X,U) se va memora numărul de vârfuri n și apoi, pentru fiecare vârf x, lista vârfurilor adiacente cu x, adică a vârfurilor y cu proprietatea că există muchia [x,y]."+
                "\n"+
                "La reprezentarea în memorie trebui avut în vedere că dimensiunile listelor de vecini sunt variabile. De aceea, este neeficientă utilizarea unor tablouri alocate static.");
        Command command8=new Command(9,"!grafPartial","Definiție. Fie G=(X, U) un graf neorientat. Se numeşte graf parțial al grafului G, graful neorientat G1=(X, U1), unde U1 ⊆ U.\n" +
                "\n" +
                "Din definiție rezultă:\n" +
                "\n" +
                "-> Un graf parțial al unui graf neorientat G=(V,U), are aceeaşi mulțime de vârfuri ca şi G, iar mulțimea muchiilor este o submulțime a lui U sau chiar U.\n" +
                "-> Fie G=(X, U) un graf neorientat. Un graf parțial al grafului G se obține păstrând vârfurile şi\n" +
                "-> eliminând eventual nişte muchii (se pot elimina şi toate muchiile sau chiar nici una).");
        Command command9=new Command(10,"!subgraf","Definiție. Fie G=(X, U) un graf orientat. Se numeşte subgraf al grafului G graful neorientat G1=(X1,U1) unde X1 ⊆ X iar U1 conține toate arcele din U care au extremitățile în X1.\n" +
                "\n" +
                "Din definiție rezultă:\n" +
                "\n" +
                "-> Fie G=(X,U) un graf orientat. Un subgraf al grafului G, se obține ştergând eventual anumite\n" +
                "-> vârfuri şi odată cu acestea şi muchiile care le admit ca extremitate (nu se pot şterge toate vârfurile deoarece s-ar obține un graf cu mulțimea vârfurilor vidă).");
        Command command10=new Command(11,"!grafComplementar","Definiție. Fie G=(X, U) un graf neorientat. Se numeşte graf complementar al grafului G, graful neorientat G1=(X, U1), cu proprietatea că două vârfuri x și y sunt adiacente în G1 dacă și numai dacă nu sunt adiacente în G.");
        Command command11=new Command(12,"!grafConex","Definiție: Un graf neorientat se numește graf conex dacă pentru oricare două vârfuri x și y diferite ale sale, există cel puțin un lanț care le leagă, adică x este extremitatea inițială și y este extremitatea finală.\n" +
                "\n" +
                "Un graf cu un singur nod este, prin definiție, conex.");
        Command command12=new Command(13,"!arbore","Definiție: Se numește arbore un graf conex și aciclic."+
                "Observații:\n" +
                "\n" +
                "-> Un arbore cu n vârfuri are n-1 muchii.\n" +
                "-> Un arbore este un graf conex și minimal cu această proprietate; dacă s-ar mai elimina o muchie, graful nu ar mai fi conex.\n" +
                "-> Un arbore este un graf aciclic și maximal cu această proprietate; dacă s-ar mai adăuga o muchie, s-ar obține un ciclu.\n" +
                "-> Un graf parțial care este arbore se numește arbore parțial.\n" +
                "\n" +
                "Un graf care nu conține cicluri se mai numește pădure. Într-o pădure fiecare componentă conexă este arbore.");
        Command command13=new Command(14,"!hamiltonian","Definiție: Se numește graf hamiltonian un graf care conține un ciclu hamiltonian. Se numește ciclu hamiltonian un ciclu elementar care conține toate vârfurile grafului."+
                "Teoremă: Un G un graf neorientat. Dacă are n≥3 vârfuri şi gradul oricărui vârf verifică inegalitatea d(x)≥n/2 atunci G este hamiltonian.");
        Command command14=new Command(15,"!eulerian","Definiție: Se numește graf eulerian un graf care conține un ciclu eulerian. Se numește ciclu eulerian un ciclu care conține toate muchiile grafului."+
                "Teoremă: Un graf G = (X,U), fără vârfuri izolate, este eulerian dacă şi numai dacă este conex şi\n" +
                "gradele tuturor vârfurilor sale sunt numere pare.");

        addCommand(command1);
        addCommand(command2);
        addCommand(command3);
        addCommand(command4);
        addCommand(command5);
        addCommand(command6);
        addCommand(command7);
        addCommand(command8);
        addCommand(command9);
        addCommand(command10);
        addCommand(command11);
        addCommand(command12);
        addCommand(command13);
        addCommand(command14);
        Command command=new Command(21,"!helpCustom","For custom bot commands!");
        addCommand(command);
    }

    private void addCommand(Command command) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("DiscordBots");
        EntityManager em = emf.createEntityManager();
        em.getTransaction().begin();
        em.persist(command);
        em.getTransaction().commit();
        em.close();
        emf.close();
    }

    private ByteArrayOutputStream exportImage(GraphDrawer frame) {
        BufferedImage image = new BufferedImage(frame.getWidth(), frame.getHeight(), BufferedImage.TYPE_INT_RGB);
        Graphics g = image.getGraphics();
        frame.paintAll(g);
        g.dispose();
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        try {
            ImageIO.write(image, "png", outputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return outputStream;
    }

    public GraphDrawer draw(Graph graph) {
        GraphDrawer frame = new GraphDrawer();
        frame.setSize(WIDTH, HEIGHT);
        frame.setVisible(true);

        int index = 1;
        int countNodes = graph.getVertexSet().size();
        while (countNodes != 0) {
            Random random = new Random();
            int randomCoordsY = random.nextInt(100);
            int yCoords = (2 * randomCoordsY * index + randomCoordsY) % WIDTH;
            int yCoords2 = (2 * randomCoordsY * index - randomCoordsY) % HEIGHT;
            int randomCoordsX = random.nextInt(100);

            if ((index) % 2 == 0)
                frame.addNode(String.valueOf(index), (randomCoordsX * index) % WIDTH, yCoords > 100 ? yCoords : yCoords + 100);
            else
                frame.addNode(String.valueOf(index), (randomCoordsX * index) % HEIGHT, yCoords2 > 100 ? yCoords2 : yCoords2 + 100);
            index++;
            countNodes--;
        }
        for (int iterator = 0; iterator < graph.getEdgeList().size(); iterator++) {
            frame.addEdge(graph.getEdgeList().get(iterator).getSourceVertex(), graph.getEdgeList().get(iterator).getDestinationVertex());
        }
        return frame;
    }

    public ColoringGraphDrawer drawColor(Graph graph,int[] coloring) {
        ColoringGraphDrawer frame = new ColoringGraphDrawer(coloring);
        frame.setSize(WIDTH, HEIGHT);
        frame.setVisible(true);

        int index = 1;
        int countNodes = graph.getVertexSet().size();
        while (countNodes != 0) {
            Random random = new Random();
            int randomCoordsY = random.nextInt(100);
            int yCoords = (2 * randomCoordsY * index + randomCoordsY) % WIDTH;
            int yCoords2 = (2 * randomCoordsY * index - randomCoordsY) % HEIGHT;
            int randomCoordsX = random.nextInt(100);

            if ((index) % 2 == 0)
                frame.addNode(String.valueOf(index), (randomCoordsX * index) % WIDTH, yCoords > 100 ? yCoords : yCoords + 100);
            else
                frame.addNode(String.valueOf(index), (randomCoordsX * index) % HEIGHT, yCoords2 > 100 ? yCoords2 : yCoords2 + 100);
            index++;
            countNodes--;
        }
        for (int iterator = 0; iterator < graph.getEdgeList().size(); iterator++) {
            frame.addEdge(graph.getEdgeList().get(iterator).getSourceVertex(), graph.getEdgeList().get(iterator).getDestinationVertex());
        }
        return frame;
    }

    public GraphBot() {
        //createCommands(); //only first time running the program to populate the database
        CustomBot customBot=new CustomBot();
        DiscordClient client = DiscordClient.create("token"); //token can't be public
        Mono<Void> login = client.withGateway((GatewayDiscordClient gateway) -> {
            // ReadyEvent example
            Mono<Void> printOnLogin = gateway.on(ReadyEvent.class, event ->
                            Mono.fromRunnable(() -> {
                                final User self = event.getSelf();
                                System.out.printf("Logged in as %s#%s%n", self.getUsername(), self.getDiscriminator());
                            }))
                    .then();

            Mono<Void> handlePingCommand = gateway.on(MessageCreateEvent.class, event -> {
                EntityManagerSingleton entityManagerSingleton = EntityManagerSingleton.getInstance();
                EntityManager entityManager = entityManagerSingleton.getEntityManagerFactory().createEntityManager();
                entityManager.getTransaction().begin();
                CommandRepository commandRepository = new CommandRepository();

                Message message = event.getMessage();
                String[] components = message.getContent().split(" ");
                switch (components[0]) {
                    case "!test", "!helpCustom",
                            "!graf", "!adiacenta", "!incidenta",
                            "!grad", "!matriceDeAdiacenta","!listaDeMuchii", "!listaDeAdiacenta",
                            "!grafPartial", "!subgraf", "!grafComplementar", "!grafConex",
                            "!arbore", "!hamiltonian", "!eulerian" -> {
                        Command function = commandRepository.findByName(components[0]);
                        entityManager.close();
                        entityManagerSingleton.closeEntityManagerFactory();
                        return message.getChannel().flatMap(channel ->
                                channel.createMessage(new StringBuilder().append(function.getResponse())
                                        .append("\n")
                                        .toString()));
                    }
                    case "!graphCommands" -> {
                        String commands = commandRepository.findAllNames();
                        entityManager.close();
                        entityManagerSingleton.closeEntityManagerFactory();
                        String output = commands + "!graph countNodes edge-edge..(even number of edges)\n"+
                                "!algorithGraph countNodes edge-edge..(even number of edges) Bfs/Dfs StartingNode\n"+
                                "!coloringAlgorithm countNodes edge-edge..(even number of edges) MinimalColoring StartingNode\n";
                        EmbedCreateSpec embed = EmbedCreateSpec.builder()
                                .title("Welcome! ^^")
                                .description("I'm AlgoBot! And i know some things about graph theory!")
                                .thumbnail("https://adatis.co.uk/wp-content/uploads/Black-n-White.png")
                                .addField("I know all this things: ", output, false)
                                .timestamp(Instant.now())
                                .build();
                        return message.getChannel().flatMap(channel -> channel.createMessage(embed));
                    }
                    case "!graph" -> {
                        try {
                            Graph graph = new Graph(components[1], components[2]);
                            GraphDrawer frame = draw(graph);
                            InputStream inputStream = new ByteArrayInputStream(exportImage(frame).toByteArray());
                            event.getMessage().getChannel().block().createMessage(messageCreateSpec ->
                            {
                                messageCreateSpec.addFile("graph.png", inputStream);
                            }).block();
                            return message.getChannel().flatMap(channel -> channel.createMessage(graph.toString()));
                        } catch (InvalidGraphException e) {
                            return message.getChannel().flatMap(channel -> channel.createMessage(e.getMessage()));
                        }
                    }
                    case "!algorithmGraph" -> {
                        AlgorithmFactory algorithmFactory = new AlgorithmFactory();
                        try {
                            Graph graph = new Graph(components[1], components[2]);
                            Algorithm algorithm;
                            if (components.length == 5) {
                                algorithm = algorithmFactory.createAlgorithm(components[3], graph, components[4]);
                            } else {
                                algorithm = algorithmFactory.createAlgorithm(components[3], graph, null);
                            }
                            GraphDrawer frame = draw(graph);
                            InputStream inputStream = new ByteArrayInputStream(exportImage(frame).toByteArray());
                            event.getMessage().getChannel().block().createMessage(messageCreateSpec ->
                            {
                                messageCreateSpec.addFile("graph.png", inputStream);
                            }).block();
                            return message.getChannel().flatMap(channel -> channel.createMessage(algorithm.algorithm()));
                        } catch (InvalidGraphException | InvalidAlgorithmException e) {
                            return message.getChannel().flatMap(channel -> channel.createMessage(e.getMessage()));
                        }
                    }
                    case "!coloringAlgorithm" -> {
                        AlgorithmFactory algorithmFactory = new AlgorithmFactory();
                        try {
                            Graph graph = new Graph(components[1], components[2]);
                            Algorithm algorithm;
                            algorithm = algorithmFactory.createAlgorithm(components[3], graph, components[4]);
                            String coloring=algorithm.algorithm();
                            int[] colors=new int[graph.getVertexSet().size()];
                            for(int iterator=0;iterator<colors.length;iterator++)
                                colors[iterator]=coloring.charAt(iterator)-48;
                            ColoringGraphDrawer frame = drawColor(graph,colors);

                            BufferedImage image = new BufferedImage(frame.getWidth(), frame.getHeight(), BufferedImage.TYPE_INT_RGB);
                            Graphics g = image.getGraphics();
                            frame.paintAll(g);
                            g.dispose();
                            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
                            try {
                                ImageIO.write(image, "png", outputStream);
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                            InputStream inputStream = new ByteArrayInputStream(outputStream.toByteArray());

                            event.getMessage().getChannel().block().createMessage(messageCreateSpec ->
                            {
                                messageCreateSpec.addFile("graph.png", inputStream);
                            }).block();
                            StringBuilder response=new StringBuilder();
                            response.append("A minimal greedy coloring for this graph starting with vertex "+ components[4]+" is:\n");
                            for(int iterator=0;iterator<coloring.length();iterator++)
                                response.append("Vertex: ").append(iterator+1).append(" has color:").append(coloring.charAt(iterator)).append("\n");
                            return message.getChannel().flatMap(channel -> channel.createMessage(String.valueOf(response)));
                        } catch (InvalidGraphException | InvalidAlgorithmException e) {
                            return message.getChannel().flatMap(channel -> channel.createMessage(e.getMessage()));
                        }
                    }
                    default -> {
                        return Mono.empty();
                    }
                }
            }).then();
            return printOnLogin.and(handlePingCommand);
        });
        login.block();
    }
}