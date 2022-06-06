package music;

import discordbots.CustomBot;

import java.util.HashMap;

public class AudioManager {
    public HashMap<Long, MusicController> controllerHashMap;

    public AudioManager(){
        this.controllerHashMap = new HashMap<Long, MusicController>();
    }

    public MusicController getMusicController(long guild){
        MusicController musicController = null;

        if(this.controllerHashMap.containsKey(guild)){
            musicController = this.controllerHashMap.get(guild);
        } else {
            musicController = new MusicController(CustomBot.getJda().getGuildById(guild));
            this.controllerHashMap.put(guild, musicController);
        }

        return musicController;
    }
}
