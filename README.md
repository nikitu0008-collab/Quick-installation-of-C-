# ⚡ Quick C++ Environment Setup for Linux

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C++-26-blue)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Linux-lightgrey)](https://www.linux.org)

> Одна команда — и ваша среда для разработки на C++ в VS Code готова к работе (clangd + минималистичная тема).

## 📦 Возможности

- ✅ Проверяет наличие **clangd** (языковой сервер для C++)
- 📥 Скачивает **clangd 18.1.3** (если отсутствует)
- 🎨 Скачивает **минималистичную тему/настройки** для VS Code
- 🔧 Написано на C++26 с использованием libcurl

## 📁 Структура проекта
├── CMakeLists.txt
├── main.cpp
├── src/
│   └── Quic-Installation-Of-C-.cpp
├── include/
│   └── Quic-Installation-Of-C-.hpp
└── README.md

## 🚀 Быстрый старт

```bash
git clone https://github.com/nikitu0008-collab/Quick-installation-of-C-.git
cd Quick-installation-of-C-
mkdir build && cd build
cmake ..
make
./cpp_setup

Программа сама предложит установить clangd и тему.
🖥 Требования

    Linux (тестировалось на Arch, Ubuntu 22.04+)

    Компилятор с поддержкой C++26 (GCC 14+ или Clang 18+)

    CMake (≥ 3.20)

    libcurl (разработка):
    bash

    sudo apt install libcurl4-openssl-dev   # Debian/Ubuntu
    # или sudo pacman -S curl               # Arch

📝 Примечания

    Скачанный clangd.zip не распаковывается автоматически – сделайте это вручную:
    bash

    unzip clangd.zip -d ~/.local/
    export PATH="$HOME/.local/clangd_18.1.3/bin:$PATH"

    Файл settings.json (тема) нужно скопировать в ~/.config/Code/User/.

    Если вы хотите последнюю версию clangd или поддержку C++26, измените URL в коде на актуальный с GitHub releases.

🔧 Сборка вручную (без CMake)
bash

g++ -std=c++26 -O2 main.cpp src/Quic-Installation-Of-C-.cpp -I include -o cpp_setup -lcurl
./cpp_setup

🤝 Улучшения, которые можно сделать

    Автоматическое определение ОС (macOS/Windows)

    Распаковка clangd.zip прямо из программы

    Добавление clangd в PATH (запись в ~/.bashrc)

    Получение последней версии clangd через GitHub API

📄 Лицензия

MIT – используйте, модифицируйте, распространяйте.

Автор: nikitu0008-collab
