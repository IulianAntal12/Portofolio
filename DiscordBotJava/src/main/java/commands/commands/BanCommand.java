package commands.commands;

import commands.types.ServerCommand;
import net.dv8tion.jda.api.Permission;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;

public class BanCommand implements ServerCommand {
    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {

        if (arguments.length == 3) { //!ban <user> <reason>
            Member target = message.getMentionedMembers().get(0);
            if (target != null) {
                String reason = arguments[2];

                if (reason != null) {
                    if (member.hasPermission(Permission.BAN_MEMBERS)) {
                        target.ban(0, reason).queue();
                    } else {
                        textChannel.sendMessage("Seems that you don't have permission to run this command").queue();
                    }

                }
            }
        } else {
            textChannel.sendMessage("Please use !ban <user> <reason>").queue();
        }
    }
}
