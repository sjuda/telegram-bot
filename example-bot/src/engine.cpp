#include "api.hpp"
#include "keyboard.hpp"
#include "utils.hpp"

// Файл, для демонстрации работы с командами и другими сообщениями

using namespace std;
using namespace TgBot;
using namespace Utils;

// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /photo
// В ответ пользователю придет сообщение с картинкой
void onCommandPhoto(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("0.jpg", "image/jpeg"));
}

// Функция для демонстрации работы с командами
// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /start
void onCommandStart(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Hi!");
}

// Функция для демонстрации работы с командами
// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /end
void onCommandEnd(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Bye!");
}

// регистрируем команды
std::map<std::string, std::function<void(Bot&, Message::Ptr)>> getAllCommands()
{
    // Ключом является идентификатор команды
    // значением является функция-обработчик коаманды
    // Например, при получении команды /end вызовется функция onCommandEnd
    std::map<std::string, std::function<void(Bot&, Message::Ptr)>> commands =
    {
        {"start", onCommandStart},
        {"end", onCommandEnd},
        {"keyboard", onCommandKeyboard},
        {"photo", onCommandPhoto}
    };

    return commands;
}



// Функция, которая вызывается при любом сообщении
void onAnyMessage(Bot& bot, Message::Ptr message)
{
    // логгируем действия в консоль
    printf("User wrote %s\n", message->text.c_str());

    // игнорируем сообщения, которые начинаются с /start и /end
    if (StringTools::startsWith(message->text, "/start"))
    {
        return;
    }
    if (StringTools::startsWith(message->text, "/end"))
    {
        return;
    }
    if (StringTools::startsWith(message->text, "/photo"))
    {
        return;
    }

    // если в тексте сообщения есть "Привет" приветствуем собеседника
    std::string hello = Utils::fromLocale("Привет");
    if (message->text.find(hello) != std::string::npos)
    {
        bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("Привет, ") + message->from->firstName);
        return;
    }

    // отправляем сообщение, которое получили
    bot.getApi().sendMessage(message->chat->id, message->from->username + ": " + message->text);
}

