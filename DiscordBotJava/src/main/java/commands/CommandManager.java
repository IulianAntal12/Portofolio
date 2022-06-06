package commands;

import commands.commands.*;
import net.dv8tion.jda.api.entities.Guild;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.TextChannel;
import net.dv8tion.jda.api.events.message.guild.GuildMessageReceivedEvent;
import net.dv8tion.jda.api.hooks.ListenerAdapter;
import org.jetbrains.annotations.NotNull;

public class CommandManager extends ListenerAdapter{
    private final HelpCommand helpCommand;
    private final ClearCommand clearCommand;
    private final BanCommand banCommand;
    private final UnbanCommand unbanCommand;
    private final PlayCommand playCommand;
    private final TicketPanelCommand ticketPanelCommand;
    private final TicketClear ticketClear;

    public CommandManager() {
        this.helpCommand = new HelpCommand();
        this.clearCommand = new ClearCommand();
        this.banCommand = new BanCommand();
        this.unbanCommand = new UnbanCommand();
        this.playCommand = new PlayCommand();
        this.ticketPanelCommand = new TicketPanelCommand();
        this.ticketClear = new TicketClear();
    }

    @Override
    public void onGuildMessageReceived(@NotNull GuildMessageReceivedEvent event) {
        if (!event.getMember().getUser().isBot()) {
            String[] arguments = event.getMessage().getContentRaw().split(" ");

            Guild guild = event.getGuild();
            Member member = event.getMember();
            TextChannel textChannel = event.getChannel();
            Message message = event.getMessage();

            switch (arguments[0]) {
                case "!help":
                    this.helpCommand.performCommand(arguments, guild, member, textChannel, message);
                    break;
                case "!clear":
                    this.clearCommand.performCommand(arguments, guild, member, textChannel, message);
                    break;
                case "!ban":
                    this.banCommand.performCommand(arguments, guild, member, textChannel, message);
                    break;
                case "!unban":
                    this.unbanCommand.performCommand(arguments, guild, member, textChannel, message);
                    break;
                case "!play":
                    this.playCommand.performCommand(arguments, guild, member, textChannel, message);
                    break;
                case "!ticketPanel":
                    this.ticketPanelCommand.performCommand(arguments, guild, member, textChannel, message);
                    break;
                case "!ticketClear":
                    this.ticketClear.performCommand(arguments, guild, member, textChannel, message);
                    break;

            }
        }
    }
}
