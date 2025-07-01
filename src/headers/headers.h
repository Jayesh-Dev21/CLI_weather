#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curl/curl.h"
#include "curl_run.h"
#include "exit.h"
#include "parser.h"


typedef struct Node{
    size_t size_arg;
    char* arg;
}node;