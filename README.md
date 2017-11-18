# telegram bot

## Настройка окружения
Для начала необходимо настроить рабочее окружение. Следуйте инструкции. 

### Windows + VisualStudio
1. Установите [7Zip](http://www.7-zip.org/)
1. Установите [CMake](https://cmake.org/download/)
1. Установите [Perl](https://www.activestate.com/activeperl/downloads). При установке поставьте галочку "Добавить в переменную окружения %PATH%"
1. Скачайте искодные коды [OpenSLL](https://www.openssl.org/source/)
1. Распакуйте OpenSLL. Например, в директорию `C:\openssl`
1. Откройте консоль
1. Выполните команду `cd C:\openssl`
1. Выполните команду `perl Configure VC-WIN32 no-asm --prefix=C:\openssl-x32-build`
1. Выполните команду `ms\do_ms`
1. Если у вас VisualStudio 2015, то выполните команду `%VS140COMNTOOLS%..\..\VC\bin\x86_amd64\vcvarsx86_amd64.bat`
1. Если у вас VisualStudio 2017, то выполните команду `%VS150COMNTOOLS%..\..\VC\bin\x86_amd64\vcvarsx86_amd64.bat`
1. Выполните команду `nmake -f ms\nt.mak`
1. Выполните команду `nmake -f ms\nt.mak install`
1. Скачайте [boost](http://www.boost.org/users/download/)
1. Распакуйте boost. Например, в директорию `C:\boost`
1. Откройте консоль
1. Выполните команду `cd C:\boost`
1. Выполните команду `bootstrap.bat`
1. Выполните команду `b2.exe threading=multi`
1. Дождитесь выполнения программы
1. Скачайте исходные коды [tgbot-cpp](https://github.com/reo7sp/tgbot-cpp)
1. Распакуйте tgbot-cpp. Например, в директорию `C:\tgbot-cpp-master`
1. Замените содержимое файла `CMakeLists.txt` на содержимое файла [CMakeLists-win-vs.txt](CMakeLists-win-vs.txt)
1. Запустите CMake
1. В поле **Where is the source code** выставьте папку где расположен tgbot-cpp. В нашем случае `C:\tgbot-cpp-master`
1. В поле **Where to build the binaries** выставьте папку где расположен tgbot-cpp. В нашем случае `C:\tgbot-cpp-master`
1. Нажмите на кнопку **Generate**
1. В открывшемся окне в верхнем поке выбираем вашу версию VisualStudio. Например, `Visaul Studio 14 2015`
1. Жмем **Finish**
1. Зажимаем кулачки
1. В случае успеха жмем кнопку **Open Project**
1. Нажимаем на клавиатуре кнопку **F7**
1. Ждем пока скомпилируется библиотека
1. Запоминаем путь до скомпилированной библиотеки. В нашем случае это `C:\tgbot-cpp-master\Debug\TgBot.lib`
1. Congratulations!

### Windows + CLion
1. Установите [7Zip](http://www.7-zip.org/)
1. Установите [Perl](https://www.activestate.com/activeperl/downloads)
1. Скачайте искодные коды [OpenSLL](https://www.openssl.org/source/)
1. Распакуйте OpenSLL. Например, в директорию `C:\openssl`
1. Откройте консоль
1. Выполните инструкцию http://wiki.qt.io/Compiling_OpenSSL_with_MinGW, используя MSYS
1. Скачайте [boost](http://www.boost.org/users/download/)
1. Распакуйте boost. Например, в директорию `C:\boost`
1. Откройте консоль
1. Выполните команду `cd C:\boost`
1. Выполните команду `bootstrap.bat`
1. Выполните команду `b2.exe threading=multi`
1. Дождитесь выполнения программы
1. Скачайте исходные коды [tgbot-cpp](https://github.com/reo7sp/tgbot-cpp)
1. Распакуйте tgbot-cpp. Например, в директорию `C:\tgbot-cpp-master`
1. ?? *тут надо что-то поменять*
1. Замените содержимое файла `CMakeLists.txt` на содержимое файла [CMakeLists-win-vs.txt](CMakeLists-win-vs.txt)
1. Запустите CMake
1. В поле **"Where is the source code"** выставьте папку где расположен tgbot-cpp. В нашем случае `C:\tgbot-cpp-master`
1. Нажмите на кнопку **"Generate"**
1. Зажимаем кулачки
1. В случае успеха жмем кнопку **"Open Project"**
1. Нажимаем на клавиатуре кнопку **F7**
1. Ждем пока скомпилируется библиотека
1. Запоминаем путь до скомпилированной библиотеки. В нашем случае это `C:\tgbot-cpp-master\Debug\TgBot.lib`
1. Congratulations!

### MacOS + CLion
1. Откройте терминал
1. Установите [brew](https://brew.sh/index_ru.html)
1. Выполните команду `brew update`
1. Выполните команду `brew install boost cmake make binutils git`
1. Выполните команду `cd ~`
1. Выполните команду `git clone https://github.com/reo7sp/tgbot-cpp.git`
1. Выполните команду `cd tgbot-cpp`
1. Выполните команду `mkdir build && cd build`
1. Выполните команду `cmake .. && make -j4`
1. Выполните команду `sudo make install`
1. Выполните команду `sudo cp libTgBot.a /usr/local/lib/`
1. Congratulations!

Процесс установки на *Mac OS* способом, который показан ниже (но для *Ubuntu*), также возможен. Нужно лишь использовать пакетный менеджер не 
`apt`, а `mac ports` или `brew`.

### Ubuntu
1. Откройте терминал
1. Выполните команду `wget -O boost_1_59_0.tar.gz http://sourceforge.net/projects/boost/files/boost/1.59.0/boost_1_59_0.tar.gz/download`
1. Выполните команду `tar xzvf boost_1_59_0.tar.gz`
1. Выполните команду `cd boost_1_59_0/`
1. Выполните команду `sudo apt-get update`
1. Выполните команду `sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential libbz2-dev`
1. Выполните команду `./bootstrap.sh --prefix=/usr/`
1. Выполните команду `./b2 threading=multi`
1. Выполните команду `sudo ./b2 install`
1. Выполните команду `sudo apt-get install g++ make binutils cmake libssl-dev libboost-dev git`
1. Выполните команду `cd ~`
1. Выполните команду `git clone https://github.com/reo7sp/tgbot-cpp.git`
1. Выполните команду `cd ~/tgbot-cpp`
1. Выполните команду `cmake .`
1. Выполните команду `make -j4`
1. Выполните команду `sudo make install`
