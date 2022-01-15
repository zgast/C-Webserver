#include <bits/types/time_t.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../config.h"

//
// Created by markus on 10/25/21.
//
void printTime() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("[%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min);
}

void yellow() {
    printf("\033[0;33m");
}


void red() {
    printf("\033[1;31m");
}

void reset() {
    printf("\033[0m");
}

void throwError(string message) {
    printTime();
    red();
    printf("ERROR: ");
    reset();
    printf("%s \n", message);
    exit(1);
}


void throwWarning(string message) {
    printTime();
    yellow();
    printf("WARNING: ");
    reset();
    printf("%s \n", message);
}

void throwLog(string message) {
    printTime();
    printf("LOG: %s \n", message);
}