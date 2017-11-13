/*
 * Copyright (c) 2015 Oleg Morozenkov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <signal.h>
#include <iostream>
#include <exception>

#include <tgbot/tgbot.h>

#include "api.hpp"
#include "utils.hpp"


using namespace std;
using namespace TgBot;
using namespace Utils;

bool sigintGot = false;


int main()
{
    // в файле token.cfg должен лежать токен вашего бота
    // никогда не показывайте его никому
    // и не заливайте в github
    Bot bot(readToken("token.cfg"));
    initBot(bot);

	signal(SIGINT, [](int s) {
		printf("SIGINT got");
		sigintGot = true;
	});

	try
    {
		printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

		TgLongPoll longPoll(bot);
		while (!sigintGot) 
        {
			printf("Long poll started\n");
			longPoll.start();
		}
	}
    catch (exception& e) 
    {
		printf("error: %s\n", e.what());
	}

	return 0;
}
