#include <cstdio>
#include <string>

#include <curl/curl.h>
#include <curl/easy.h>
#include <cstdlib>

#include "../include/Quic-Installation-Of-C-.hpp"

class Quic::Quic{
    public:
    static auto write_callback(void *contents, size_t size, size_t nmemb, void *userp) -> size_t {
        size_t const total = size * nmemb;
        FILE *f = static_cast<FILE*>(userp);
        return fwrite(contents, 1, total, f);
    }

    static auto download_file(const std::string &url, const std::string &out_path) -> bool {
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

    static auto is_installed(const std::string &cmd) -> bool {
        std::string check = "which " + cmd + " > /dev/null 2>&1";
        return system(check.c_str()) == 0;
    }
};
