#pragma once
#include <string>
#include <unordered_map>

class HttpResponse
{
public:
    explicit HttpResponse() noexcept(true)
    {
    }
    void setStatus (int code, const std::string& phrase);
    void setHeader (const std::string &key, const std::string &value);
    void setBody (const std::string &body);

private:
    int status;
    std::unordered_map<std::string, std::string> header;
    std::string body;
};