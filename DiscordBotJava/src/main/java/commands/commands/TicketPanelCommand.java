package commands.commands;

import commands.types.ServerCommand;
import net.dv8tion.jda.api.EmbedBuilder;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;

import java.util.HashMap;

public class TicketPanelCommand implements ServerCommand {

    public static HashMap<Long, String> ticket_panel = new HashMap<>();

    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {
        if(arguments.length == 2) { // !ticketPanel <channel>
            TextChannel textChannel1 = message.getMentionedChannels().get(0);
            if(textChannel1 != null){
                EmbedBuilder embedBuilder = new EmbedBuilder();

                embedBuilder.setColor(0x6C8EAD);
                embedBuilder.setTitle(("Ticket title"));
                embedBuilder.setDescription("React to this panel to receive support from \n a staff member, by creating a channel, please do not\nabuse this little cool feature.");

                textChannel1.sendMessage(embedBuilder.build()).queue(message1 -> {
                    message1.addReaction("✉").queue();
                    long guildID = guild.getIdLong();
                    String messageID = message1.getId();
                    if(!ticket_panel.containsKey(guildID)) {
                        ticket_panel.put(guildID, messageID);
                    }
                });
            }
        }
    }
}