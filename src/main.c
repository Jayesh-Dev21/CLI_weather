#include "headers/headers.h"

int main(int argc, char *argv[]) {
    // Initialize the application
    if(argc <= 1){
        fprintf(stderr, "Failed to initialize the application.\nPlease Enter the city to begin.\n");
        return exit_failure();
    }
    if(argc > 2){
        fprintf(stderr, "Error, enter one parameter only.\nPlease enter the city to begin.\n");
        return exit_failure();
    }

    const char* weather_url_route = "https://wttr.in/";
    const char* weather_url_route_end = "?ATm";
    const char* city_name = argv[1];
    
    size_t request_len = strlen(weather_url_route) + strlen(argv[1]) + strlen(weather_url_route_end) + 1;
    char *request = malloc(request_len);
    if (request == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        return exit_failure();
    }

    strcpy(request,weather_url_route);
    strcat(request, city_name);
    strcat(request, weather_url_route_end);
    
    node result = run_curl(request);
    char* buff = malloc(result.size_arg);
    snprintf(buff, result.size_arg, "%s", result.arg);
    size_t buff_size = strlen(buff);
    
    char* parsed_buff = parse(buff, buff_size);
    size_t len_p_buff = strlen(parsed_buff);
    
    fwrite(parsed_buff, 1, len_p_buff-1, stdout);

    free(request);
    free(buff);
    return exit_success();
}