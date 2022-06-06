package commands.commands;

import commands.types.ServerCommand;
import net.dv8tion.jda.api.Permission;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;

public class TicketClear implements ServerCommand {
    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {
        if(arguments.length == 1) { // !ticketClear
            if(textChannel.getName().contains("ticket-")){
                if(member.hasPermission(Permission.ADMINISTRATOR)){
                    member.getUser().openPrivateChannel().queue(privateChannel -> {
                        privateChannel.sendMessage("Successfully closed the ticket with the id - "+ textChannel.getId()).queue();
                    });
                    textChannel.delete().queue();
                } else {
                    textChannel.sendMessage("Sorry, but it seems you don't have the right permissions to perform this action.");
                }
            } else {
                textChannel.sendMessage("Sorry, but this channel does not seems to be your ticket channel");
            }
        }
    }
}
