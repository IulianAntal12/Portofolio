package commands.events;

import commands.commands.TicketPanelCommand;
import net.dv8tion.jda.api.Permission;
import net.dv8tion.jda.api.events.message.guild.react.GuildMessageReactionAddEvent;
import net.dv8tion.jda.api.hooks.ListenerAdapter;
import org.jetbrains.annotations.NotNull;


public class ReactionAddEvent extends ListenerAdapter {

    private Integer count = 1;
    private String id = "";

    @Override
    public void onGuildMessageReactionAdd(@NotNull GuildMessageReactionAddEvent event) {
        if (!event.getMember().getUser().isBot()) {
            if (event.getReactionEmote().getName().equals("✉")) {
                long guildID = event.getGuild().getIdLong();
                String rawMessageID = TicketPanelCommand.ticket_panel.get(guildID);
                if (rawMessageID.equals(event.getMessageId())) {
                    id = null;
                    event.getReaction().removeReaction(event.getUser()).queue();

                    event.getGuild().createTextChannel("ticket-" + count.toString()).queue(textChannel -> {
                        textChannel.createPermissionOverride(event.getMember()).setAllow(Permission.VIEW_CHANNEL, Permission.MESSAGE_WRITE);
                        textChannel.createPermissionOverride(event.getGuild().getRoleById("983265024841760818")).setAllow(Permission.VIEW_CHANNEL, Permission.MESSAGE_WRITE).queue();
                        id = textChannel.getId();
                    });
                    event.getMember().getUser().openPrivateChannel().queue(privateChannel -> {
                        privateChannel.sendMessage("You have successfully created a ticket - " + id).queue();
                    });
                    count += 1;
                }
            }
        }
    }
}
