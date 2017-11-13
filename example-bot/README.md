## Компиляция тестого бота
До выполнения этой инструкции вы должны настроить окружение. [Читайте тут](../README.md)

### Получение токена для бота
1. Ознакомьтесь с [ссылкой](https://tlgrm.ru/docs/bots)
1. Добавьте в ваш телеграм [@BotFather](https://telegram.me/botfather)
1. Напишите этому боту сообщение `/newbot`
1. Следуйте инструкции
1. @BotFather пришлет вам токен

### Windows
1. Выполните в консоле команду `setx TgBot_LIB "ПУТЬ ДО СКОМПИЛИРОВАННОЙ БИБЛИОТЕКИ TgBot"`. Пример, `setx TgBot_LIB "C:\tgbot-cpp-master\Debug\TgBot.lib"`
1. Выполните в консоле команду `setx TgBot_INCLUDE_DIR "ПУТЬ ДО ЗЗАГОЛОВОЧНЫХ ФАЙЛОВ БИБЛИОТЕКИ TgBot"`. Пример, `setx TgBot_LIB "C:\tgbot-cpp-master\include"`
1. Запустите CMake
1. В поле **Where is the source code** выставьте папку до директории `example-bot`.
1. В поле **Where to build the binaries** выставьте папку где расположен `example-bot`.
1. Нажмите на кнопку **Generate**
1. В открывшемся окне в верхнем поке выбираем вашу версию VisualStudio. Например, `Visaul Studio 14 2015`
1. Жмем **Finish**
1. Зажимаем кулачки
1. В случае успеха жмем кнопку **Open Project**
1. Нажимаем на клавиатуре кнопку **F7**
1. Ждем пока скомпилируется приложение
1. Создаем файл `token.cfg` и записываем в него токен вашего бота
1. Запускаем приложение. Бот работает.

### MacOS
1. Откройте терминал
1. Установите [brew](https://brew.sh/index_ru.html)
1. Выполните команду `brew update`
1. Выполните команду `brew install boost cmake make binutils git`
1. Выполните команду `cd ~`
1. Выполните команду `git clone https://github.com/bmstu-iu8-11-cpp-2017/homework-telegram-bot.git`
1. Выполните команду `cd homework-telegram-bot/example-bot`
1. Выполните команду `mkdir build && cd build`
1. Выполните команду `cmake .. && make -j4`
1. Создаем файл `token.cfg` и записываем в него токен вашего бота
1. Запускаем приложение. Бот работает.

### Ubuntu
1. Откройте терминал
1. Выполните команду `cd ~`
1. Выполните команду `git clone https://github.com/bmstu-iu8-11-cpp-2017/homework-telegram-bot.git`
1. Выполните команду `cd homework-telegram-bot/example-bot`
1. Выполните команду `mkdir build && cd build`
1. Выполните команду `cmake .. && make -j4`
1. Создаем файл `token.cfg` и записываем в него токен вашего бота
1. Запускаем приложение. Бот работает.
