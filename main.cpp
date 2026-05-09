#include <string>
#include <cstdlib>
#include <iostream>
#include <print>

#include <curl/curl.h>
#include <curl/easy.h>

#include "include/Quic-Installation-Of-C-.hpp"
auto main() -> int {
    Quic quic;
    curl_global_init(CURL_GLOBAL_DEFAULT);

    std::string answer;
    if (!quic.is_installed("clangd")) {
        std::println("clangd not found. Install? [Y/n]");
        std::cin >> answer;
        if (answer == "Y" || answer == "y") {
            //Cкачать clangd для Linux (измените URL под вашу ОС)
            const std::string url = "https://github.com/clangd/clangd/releases/download/18.1.3/clangd-linux-18.1.3.zip";
            if (quic.download_file(url, "clangd.zip")) {
                std::println("clangd downloaded. Extract manually or use system package.");
            } else {
                std::println("Download failed.");
            }
        }
    } else {
        std::println("[✓] clangd");
    }

    std::println("Install minimalistic theme? [Y/n]");
    std::cin >> answer;
    if (answer == "Y" || answer == "y") {
        // Ссылка на файл темы (например, .vsix или .json)
        const std::string theme_url = "https://github.com/nikitu0008-collab/VS-Code-Minimalist-Settings-Clean-distraction-free-editor-config/blob/main/settings.json";
        if (quic.download_file(theme_url, "settings.json")) {
            std::println("Theme downloaded.");
        } else {
            std::println("Theme download failed.");
        }
    }
    std::println("[✓] All download completed");
    curl_global_cleanup();
    return EXIT_SUCCESS;
}
