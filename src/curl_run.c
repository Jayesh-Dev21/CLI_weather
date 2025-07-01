#include "headers/headers.h"
#include "headers/curl_run.h"

node run_curl(char *request){
    CURL *curl;
    CURLcode response;
    node out;
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, request);

        response = curl_easy_perform(curl);

        if(response != CURLE_OK){
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response));
        }

        else{
            out.size_arg = sizeof(response);
            snprintf(out.arg, out.size_arg, response);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return out;
}