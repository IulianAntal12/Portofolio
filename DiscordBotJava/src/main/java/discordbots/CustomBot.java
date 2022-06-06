package discordbots;

import com.sedmelluq.discord.lavaplayer.player.AudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.player.DefaultAudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.source.AudioSourceManagers;
import commands.CommandManager;
import commands.events.ReactionAddEvent;
import music.AudioManager;
import net.dv8tion.jda.api.JDA;
import net.dv8tion.jda.api.JDABuilder;
import net.dv8tion.jda.api.OnlineStatus;
import net.dv8tion.jda.api.entities.Activity;

import javax.security.auth.login.LoginException;

public class CustomBot {
    private static JDA jda;
    private static JDABuilder jdaBuilder;
    private static AudioPlayerManager audioPlayerManager;
    private static AudioManager audioManager;
    public CustomBot(){
        jdaBuilder = JDABuilder.createDefault("token"); //token can't be public

        jdaBuilder.setStatus(OnlineStatus.IDLE);
        jdaBuilder.setActivity(Activity.playing("Create discord bot"));

        audioPlayerManager = new DefaultAudioPlayerManager();
        audioManager = new AudioManager();

        try {
            jda = jdaBuilder.build();
        } catch (LoginException exception) {
            exception.printStackTrace();
        }

        AudioSourceManagers.registerRemoteSources(audioPlayerManager);

        registerCommands();
        registerEvents();
    }
    private static void registerCommands(){
        CommandManager commandManager = new CommandManager();
        jda.addEventListener(commandManager);
    }

    public static JDA getJda(){
        return jda;
    }

    public static AudioPlayerManager getAudioPlayerManager() {
        if (audioPlayerManager != null) {
            return audioPlayerManager;
        }
        return null;
    }

    public static AudioManager getAudioManager(){
        return audioManager;
    }

    private static void registerEvents(){
        ReactionAddEvent reactionAddEvent = new ReactionAddEvent();
        jda.addEventListener(reactionAddEvent);
    }
}
