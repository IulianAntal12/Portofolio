package music;

import com.sedmelluq.discord.lavaplayer.player.AudioPlayer;
import discordbots.CustomBot;
import net.dv8tion.jda.api.entities.Guild;

public class MusicController {
    private final Guild guild;
    private final AudioPlayer audioPlayer;

    public MusicController(Guild guild) {
        this.guild = guild;
        this.audioPlayer = CustomBot.getAudioPlayerManager().createPlayer();

        this.guild.getAudioManager().setSendingHandler(new AudioPlayerSendHandler(audioPlayer));
        this.audioPlayer.setVolume(150);
    }

    public Guild getGuild() {
        return guild;
    }

    public AudioPlayer getAudioPlayer() {
        return this.audioPlayer;
    }
}
