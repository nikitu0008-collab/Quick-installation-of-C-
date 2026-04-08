#include <cstdio>
#include <iostream>
#include <string>
#include <print>
#include <fstream>
#include <curl/curl.h>
#include <curl/easy.h>

auto write_callback(void *contents, size_t size, size_t nmemb, void *userp) -> size_t {
    size_t total = size * nmemb;
    FILE *f = static_cast<FILE*>(userp);
    return fwrite(contents, 1, total, f);
}

auto download_file(const std::string &url, const std::string &out_path) -> bool {
    CURL *curl = curl_easy_init();
    if (!curl) return false;
    FILE *file = fopen(out_path.c_str(), "wb");
    if (!file) {
        curl_easy_cleanup(curl);
        return false;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    CURLcode res = curl_easy_perform(curl);
    fclose(file);
    curl_easy_cleanup(curl);
    return res == CURLE_OK;
}

auto is_installed(const std::string &cmd) -> bool {
    std::string check = "which " + cmd + " > /dev/null 2>&1";
    return system(check.c_str()) == 0;
}

auto main() -> int {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    std::string answer;
    if (!is_installed("clangd")) {
        std::println("clangd not found. Install? [Y/n]");
        std::cin >> answer;
        if (answer == "Y" || answer == "y") {
            //Cкачать clangd для Linux (измените URL под вашу ОС)
            std::string url = "https://github.com/clangd/clangd/releases/download/18.1.3/clangd-linux-18.1.3.zip";
            if (download_file(url, "clangd.zip")) {
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
        std::string theme_url = "https://github.com/nikitu0008-collab/VS-Code-Minimalist-Settings-Clean-distraction-free-editor-config/blob/main/settings.json";
        if (download_file(theme_url, "settings.json")) {
            std::println("Theme downloaded.");
        } else {
            std::println("Theme download failed.");
        }
    }
    std::println("[✓] All download completed");
    curl_global_cleanup();
    return EXIT_SUCCESS;
}
