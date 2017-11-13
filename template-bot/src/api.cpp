#include "api.hpp"

using namespace TgBot;

std::string readToken(const std::string& filename)
{
    std::ifstream telegramTokenFile(filename);
    std::string token;
    telegramTokenFile >> token;
    return token;
}

void initBot(Bot& bot)
{
    for (const auto& c : getAllCommands())
    {
        auto func = c.second;
        bot.getEvents().onCommand(c.first, [&bot, func](Message::Ptr message) {
            func(bot, message);
        });
    }

    bot.getEvents().onCallbackQuery([&bot](CallbackQuery::Ptr query) {

        for (const auto& c : getAllCallbacks())
        {
            if (c.first == query->data)
            {
                auto func = c.second;
                func(bot, query);
                return;
            }
        }

        bot.getApi().sendMessage(query->message->chat->id, "Unknown control!!!");
    });

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
        onAnyMessage(bot, message);
    });
}