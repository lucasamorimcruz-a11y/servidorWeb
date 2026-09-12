#include "HttpRequest.hpp"

HttpRequest::HttpRequest() noexcept(true)
{
}
void HttpRequest::parseRequest(const std::string &originalRequest)
{
}
std::string HttpRequest::getMethod() const noexcept(true)
{
}
std::string HttpRequest::getPath() const noexcept(true)
{
}
std::string HttpRequest::getHeader(const std::string &key) const noexcept(true)
{
}
std::string HttpRequest::getBody() const noexcept(true)
{
}