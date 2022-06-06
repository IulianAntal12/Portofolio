package commands;

import javax.persistence.*;
import java.io.Serializable;

@Entity
@Table(name = "commands")
@NamedQueries({
        @NamedQuery(name = "Command.findByName",
                query = "select e from Command e where e.command = :command"),
        @NamedQuery(name = "Command.findAllNames",
                query = "select e.command from Command e")
})
public class Command implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY, generator = "id")
    @Column(name = "id")
    private Integer id;

    @Column(name = "command")
    private String command;

    @Column(name = "response")
    private String response;

    public Command() {

    }

    public Command(Integer id, String command, String response) {
        this.id = id;
        this.command = command;
        this.response = response;
    }

    public String getResponse() {
        return response;
    }


    @Override
    public String toString() {
        return "Command{" +
                "id=" + id +
                ", command='" + command + '\'' +
                ", response='" + response + '\'' +
                '}';
    }
}
