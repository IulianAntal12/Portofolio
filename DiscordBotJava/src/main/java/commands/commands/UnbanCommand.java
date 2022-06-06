package commands.commands;

import commands.types.ServerCommand;
import net.dv8tion.jda.api.Permission;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;

public class UnbanCommand implements ServerCommand {
    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {
        if (arguments.length == 2) { // !unban <user>
            if (member.hasPermission(Permission.BAN_MEMBERS)) {
                String id = arguments[1];
                guild.unban(id).queue();
            } else {
                textChannel.sendMessage("Seems that you don't have permission to run this command").queue();
            }
        } else {
            textChannel.sendMessage("Please use !unban <user>").queue();
        }
    }
}

