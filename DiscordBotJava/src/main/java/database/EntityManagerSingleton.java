package database;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class EntityManagerSingleton {
    private static final EntityManagerSingleton instance = new EntityManagerSingleton();
    protected EntityManagerFactory entityManagerFactory;

    private EntityManagerSingleton() {
    }

    public static EntityManagerSingleton getInstance() {
        return instance;
    }

    public EntityManagerFactory getEntityManagerFactory() {
        if (entityManagerFactory == null)
            createEntityManagerFactory();
        return entityManagerFactory;
    }

    public void closeEntityManagerFactory() {
        if (entityManagerFactory != null) {
            entityManagerFactory.close();
            entityManagerFactory = null;
        }
    }

    protected void createEntityManagerFactory() {
        this.entityManagerFactory = Persistence.createEntityManagerFactory("DiscordBots");
    }
}