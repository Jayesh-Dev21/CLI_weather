#include "headers/exit.h"
#include "headers/headers.h"


int exit_success(void){
    return EXIT_SUCCESS;
}

int exit_failure(void){
    return EXIT_FAILURE;
}

node node_exit_failure(void){
    node exit_error;
    exit_error.arg = NULL;
    exit_error.size_arg = 0;
    return exit_error;
}