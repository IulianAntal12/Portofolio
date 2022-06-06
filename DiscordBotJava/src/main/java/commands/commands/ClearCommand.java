package commands.commands;
import commands.types.ServerCommand;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;
import net.dv8tion.jda.api.exceptions.InsufficientPermissionException;

import java.util.List;

public class ClearCommand implements ServerCommand {
    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {
        if (arguments.length < 2) { //!clear <amount>
            textChannel.sendMessage("Please specify the amount of messages you want to clear").queue();
        } else {
            try {
                try {
                    message.delete().queue();
                } catch (InsufficientPermissionException exception) {
                    textChannel.sendMessage("Sorry, but I don't have enough permission for this action").queue();
                }

                List<Message> messageList = textChannel.getHistory().retrievePast(Integer.parseInt(arguments[1])).complete();
                textChannel.deleteMessages(messageList).queue();

                textChannel.sendMessage("Successfully cleared " + arguments[1] + " messages in " + textChannel.getAsMention()).queue();
            } catch (IllegalArgumentException exception) {
                if (exception.toString().startsWith("java.lang.IllegalArgumentException: Message retrieval")) {
                    textChannel.sendMessage("Sorry, but you can't delete more than 100 messages at once").queue();
                } else {
                    textChannel.sendMessage("Sorry, but you can't delete messages that are older than 2 weeks").queue();
                }
            }
        }
    }
}
