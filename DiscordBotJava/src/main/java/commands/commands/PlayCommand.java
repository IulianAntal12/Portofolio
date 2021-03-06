package commands.commands;

import com.sedmelluq.discord.lavaplayer.player.AudioLoadResultHandler;
import com.sedmelluq.discord.lavaplayer.player.AudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.tools.FriendlyException;
import com.sedmelluq.discord.lavaplayer.track.AudioPlaylist;
import com.sedmelluq.discord.lavaplayer.track.AudioTrack;
import discordbots.CustomBot;
import commands.types.ServerCommand;
import music.MusicController;
import net.dv8tion.jda.api.entities.*;
import net.dv8tion.jda.api.managers.AudioManager;

public class PlayCommand implements ServerCommand {
    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {
        if (arguments.length == 2) { // !play <url>
            GuildVoiceState voiceState;
            if ((voiceState = member.getVoiceState()) != null) {
                VoiceChannel voiceChannel;
                if ((voiceChannel = voiceState.getChannel()) != null) {
                    MusicController musicController = CustomBot.getAudioManager().getMusicController(voiceChannel.getGuild().getIdLong());
                    AudioPlayerManager audioPlayerManager = CustomBot.getAudioPlayerManager();
                    AudioManager audioManager = voiceState.getGuild().getAudioManager();

                    audioManager.openAudioConnection(voiceChannel);

                    StringBuilder builder = new StringBuilder();
                    for (int i = 1; i < arguments.length; i++) builder.append(arguments[i] + " ");

                    String rawLink = builder.toString().trim();
                    if(!rawLink.startsWith("http")){
                        rawLink = "ytsearch: " + rawLink;
                    }

                    final String url = rawLink;
                    audioPlayerManager.loadItem(url, new AudioLoadResultHandler() {
                        @Override
                        public void trackLoaded(AudioTrack audioTrack) {
                            musicController.getAudioPlayer().playTrack(audioTrack);
                        }

                        @Override
                        public void playlistLoaded(AudioPlaylist audioPlaylist) {

                        }

                        @Override
                        public void noMatches() {

                        }

                        @Override
                        public void loadFailed(FriendlyException e) {

                        }
                    });

                } else {
                    textChannel.sendMessage("You need to be in a voice channel to execute this command").queue();
                }
            } else {
                textChannel.sendMessage("You need to be in a voice channel to execute this command").queue();
            }
        }
    }
}
