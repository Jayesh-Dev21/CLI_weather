#include "headers/parser.h"
#include "headers/headers.h"

char* parse(char *arg, unsigned long size){
    char* p_buff = malloc(size+1);
    
    strncpy(p_buff, arg, size);
    p_buff[size] = '\0';

    char *rm_line = strstr(p_buff, "Follow @");
    if(rm_line){*rm_line = '\0';}
    
    return p_buff;
}