#pragma once
#include <string>
#include <unordered_map>
class HttpRequest
{
public:
    explicit HttpRequest() noexcept(true);
    void parseRequest(const std::string &originalRequest);
    [[nodiscard]] std::string getMethod() const noexcept (true);
    [[nodiscard]] std::string getPath() const noexcept(true);
    [[nodiscard]] std::string getHeader(const std::string &key) const noexcept(true);
    [[nodiscard]] std::string getBody() const noexcept(true);

private:
    std::string method;
    std::string path;
    std::unordered_map <std::string, std::string> header;
    std::string body;
};