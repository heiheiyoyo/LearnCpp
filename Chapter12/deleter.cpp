#include <iostream>
#include <memory>
#include <curl/curl.h>

int main()
{
    CURLcode res;
    std::shared_ptr<CURL> curl(curl_easy_init(),[](CURL* c){if(c)curl_easy_cleanup(c);});
    //std::unique_ptr<CURL,decltype(curl_easy_cleanup) *> curl(curl_easy_init(),curl_easy_cleanup);
    curl_easy_setopt(curl.get(),CURLOPT_URL,"http://www.baidu.com/");
    curl_easy_setopt(curl.get(),CURLOPT_FOLLOWLOCATION,1L);
    res=curl_easy_perform(curl.get());
    if(res!=CURLE_OK)
    {
        std::cerr<<"curl_easy_perform() failed: "<<curl_easy_strerror(res)<<"\n";
    }
    else
    {
        char *ct;
        res=curl_easy_getinfo(curl.get(),CURLINFO_CONTENT_TYPE,&ct);
        if((res==CURLE_OK)&&ct)
        {
            std::cout<<"We received Content-Type: "<<ct<<std::endl;
        }
    }
    

    std::cout<<"Quit";
    return 0;
}