#include <iostream>
#include <curl/curl.h>

class Curl
{
public:
    Curl() { curlPtr = curl_easy_init(); }
    Curl(const char *URL);
    Curl(const Curl&)=delete;
    Curl& operator=(const Curl&)=delete;
    ~Curl();

    void setURL(const char *URL);
    void perform();
    const char *getContent();
    void reset();
    bool isInit() { return (curlPtr) ? true : false; }

private:
    CURL *curlPtr;
    CURLcode res;
    bool isPerformed = false;
    bool urlSetted = false;
};

Curl::Curl(const char *URL)
{
    curlPtr = curl_easy_init();
    if (curlPtr)
    {
        curl_easy_setopt(curlPtr, CURLOPT_URL, URL);
        urlSetted = true;
    }
}

void Curl::setURL(const char *URL)
{
    if (curlPtr)
    {
        curl_easy_setopt(curlPtr, CURLOPT_URL, URL);
        urlSetted = true;
    }
}

void Curl::reset()
{
    if (curlPtr)
    {
        curl_easy_reset(curlPtr);
    }
}

void Curl::perform()
{
    if (curlPtr && urlSetted)
    {
        res = curl_easy_perform(curlPtr);
        isPerformed = true;
    }
}

const char *Curl::getContent()
{

    const char *c = nullptr;
    if (curlPtr && isPerformed && (res == CURLE_OK))
    {

        res = curl_easy_getinfo(curlPtr, CURLINFO_CONTENT_TYPE, &c);
    }
    return c;
}

Curl::~Curl()
{
    if (curlPtr)
    {
        curl_easy_cleanup(curlPtr);
    }
}

int main()
{
    Curl c;
    c.setURL("https://heiheiyoyo.tk/");
    c.perform();
    std::cout << c.getContent();
}