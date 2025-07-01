#include "headers/exit.h"
#include "headers/headers.h"


int exit_success(void){
    cleanup_app();
    
    return EXIT_SUCCESS;
}

int exit_failure(void){
    cleanup_app();
    
    return EXIT_FAILURE;
}