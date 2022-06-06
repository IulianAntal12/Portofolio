package commands.commands;

import commands.types.ServerCommand;
import net.dv8tion.jda.api.EmbedBuilder;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;

public class HelpCommand implements ServerCommand {
    @Override
    public void performCommand(String[] arguments, Guild guild, Member member, TextChannel textChannel, Message message) {
        EmbedBuilder embedBuilder = new EmbedBuilder();

        embedBuilder.setColor(0x653239);
        embedBuilder.setTitle("Useful commands");
        embedBuilder.setDescription("**!help** - *prints this embed*\n" +
                "**!clear <integer n>** - *clears n messages*\n" +
                "**!ban <user> <reason>** - *bans user*\n" +
                "**!unban <user>** - *unban user*\n" +
                "**!ticketPanel <channel>** - *opens new ticket*\n" +
                "**!ticketClear** - *clears current ticket*\n" +
                "**!play <url>** - *play music from youtube in voice channel*\n" +
                "**!graphCommands** - *por graph commands*"
        );

        textChannel.sendMessage((embedBuilder.build())).queue();
    }
}
