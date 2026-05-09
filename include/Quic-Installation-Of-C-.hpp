#include <cstdio>
#include <string>
class Quic{
    public:
        Quic()= default;
        ~Quic()= default;
        auto write_callback(void *contents, size_t size, size_t nmemb, void *userp)->size_t{}
        auto download_file(const std::string &url, const std::string &out_path)->bool{}
        auto is_installed(const std::string &cmd)->bool{} 
    private:
};
