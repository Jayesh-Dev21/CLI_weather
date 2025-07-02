#include "headers/headers.h"
#include "headers/curl_run.h"

node run_curl(char *request){
    CURL *curl;
    CURLcode response_code;
    node out;
    out.arg = "NULL";
    out.size_arg = 0;
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if(!curl){
        fprintf(stderr, "init failed\n");
        return node_exit_failure();
    }

    FILE *fp = tmpfile(); // temp file creation -- auto delete
    if (!fp) {
        perror("tmpfile");
        return out;
    }

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, request);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        response_code = curl_easy_perform(curl);

        if(response_code != CURLE_OK){
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response_code));
        }

        else{
            fseek(fp, 0, SEEK_END); // reads the new file size
            long size = ftell(fp);
            rewind(fp); // moves the pointer back to the start of the fiel
            out.arg = malloc(size + 1); // allocate memory to response arg
            fread(out.arg, 1, size, fp); // concatenates the data form file to response nofe output arg
            out.size_arg = size;
        }
        curl_easy_cleanup(curl); // cleans the curl pointer, no can be used for new request as well
    }
    curl_global_cleanup(); // clears the complete curl instance data

    fclose(fp); // closes the tmp file
    return out; // returns the output node
}