#include "headers/headers.h"

int main(int argc, char *argv[]) {
    // Initialize the application
    if (!init_app(argc, argv)) {
        fprintf(stderr, "Failed to initialize the application.\n");
        return exit_failure();
    }

    char *request = NULL;
    char* buff;
    size_t buffer_size = sizeof(buff);

    node result = run_curl(request);

    snprintf(buff, result.size_arg, result.arg);

    return exit_success();
}