//
// Created by markus on 10/30/21.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include "../config.h"
#include "../utils/logger.h"
#include "./contentTypes.h"

SendData setHttpHeader(string request, string path) {
    string route;
    char tmp[500];

    memset(tmp, 0, 10);

    int i = 4;

    while (request[i] != ' ') {
        strncat(tmp, &request[i], 1);
        i++;

    }
    if (tmp[2] == '0') {
        route = "";
    } else {
        route = tmp;
    }


    SendData returnData;
    char *contentType = (char *) calloc(100, sizeof(char));
    char *header = (char *) calloc(50000, sizeof(char));
    char fullpath[(strlen(route) + strlen(path)) - 3];
    char *contentBuffer = (char *) calloc(50000, sizeof(char));
    memset(fullpath, 0, 10);


    strcat(fullpath, path);
    strcat(fullpath, route);


    for (int i = 0; 11 > i; i++) {
        if (strstr(fullpath, contentTypes[i].ending) != NULL) {

            strcat(contentType, contentTypes[i].header);
            i = sizeof(contentTypes);
        }
    }


    if (!contentType[0]) {
        strcat(fullpath, "/index.html");
    }

    throwLog(fullpath);
    if (access(fullpath, F_OK) == 0) {

        FILE *file = fopen(fullpath, "rb");

        int fileSize = fread(contentBuffer, 1, 50000, file);

        sprintf(header,
                "HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n",
                contentType
        );

        memcpy(header + strlen(header), contentBuffer, fileSize);


        returnData.size = fileSize;
        returnData.header = header;


        fclose(file);
        free(contentBuffer);

    } else {
        throwWarning("File requested not found");
        strcat(header, "HTTP/1.1 404 Not Found\r\n\n");

        returnData.size = strlen(header);
        returnData.header = header;

    }

    return returnData;
}