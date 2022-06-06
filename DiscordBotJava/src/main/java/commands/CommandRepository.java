package commands;

import database.EntityManagerSingleton;

import javax.persistence.EntityManager;

public class CommandRepository {
    EntityManagerSingleton entityManagerSingleton = EntityManagerSingleton.getInstance();
    private EntityManager entityManager = entityManagerSingleton.getEntityManagerFactory().createEntityManager();

    public Command findByName(String command) {
        return (Command) entityManager.createNamedQuery("Command.findByName").setParameter("command", command).getSingleResult();
    }

    public String findAllNames() {
        StringBuilder commandList = new StringBuilder();
        var commands = entityManager.createNamedQuery("Command.findAllNames").getResultList();
        for (Object command : commands) {
            commandList.append(command);
            commandList.append("\n");
        }
        return commandList.toString();
    }
}
