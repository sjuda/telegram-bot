#include "api.hpp"
#include "keyboard.hpp"
#include "utils.hpp"
#include <iostream>

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
		{ "start", onCommandStart },
		{ "end", onCommandEnd },
		{ "keyboard", onCommandKeyboard },
		{ "photo", onCommandPhoto }
	};

	return commands;
}



// Функция, которая вызывается при любом сообщении
struct gamma { unsigned char state[4]; };
gamma new_gamma(unsigned char key[4])
{
	srand(*key);
	gamma gw;
	for (int i = 0; i < 4; i++)
	{
		gw.state[i] = rand();
	}
	return gw;
}
gamma g = new_gamma((unsigned char*)"228");
unsigned char encryption(unsigned char str[4], gamma g)
{
	unsigned char cipher[4];
	*cipher = *str ^ *g.state;
	int f = 1;
	int r = *cipher & f;
	r = r << 7;
	*cipher = *cipher << 1;
	*cipher |= r;
	return *cipher;
}
unsigned char decryption(unsigned char str[4], gamma g)
{
	int f = 1;
	int r = *str & f;
	r = r << 7;
	*str = *str << 1;
	*str |= r;
	*str = *str ^ *g.state;
	return *str;
}
void onAnyMessage(Bot& bot, Message::Ptr message)
{
	if (StringTools::startsWith(message->text, "/encrypt"))
	{
		bot.getApi().sendMessage(message->chat->id, encryption(message->text));
	}
	if (StringTools::startsWith(message->text, "/decrypt"))
	{
		bot.getApi().sendMessage(message->chat->id, dencryption(message->text,g));
	}
}
