//
// Created by markus on 10/24/21.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils/logger.h"


void helpPrint();

ArgumentResult arguments(int argc, char *argv[]) {
    ArgumentResult result;
    result.port = 8080;
    result.path = "./";

    if (argc > 1) {
        if (argc > 4) {
            throwError("Too many arguments");
        } else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0) {
            helpPrint();
        } else if (strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "--port") == 0) {
            result.port = atoi(argv[2]);
            if (argc == 4) {
                result.path = argv[3];
            } else {
                throwWarning("No part specified, the standard path is ./");
            }
        } else if (argc == 2) {
            result.path = argv[1];
            throwWarning("No port specified, the standard port is 8080");
        }
    } else {
        throwWarning("No port and no path specified, the standard port is 8080 and the standard path is ./");
    }

    return result;
}

void helpPrint() {
    printf("----------------------------------------------------------------------------\n");
    printf("|          webserver listens per default on port 8080                      |\n");
    printf("|   webserver <flags> <path> (<> is optional) is the general syntax        |\n");
    printf("|                                                                          |\n");
    printf("|            -p <port> or --port <port> to change port                     |\n");
    printf("----------------------------------------------------------------------------");
    exit(0);
}