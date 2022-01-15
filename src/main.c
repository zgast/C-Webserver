#include <stdio.h>
#include "config.h"
#include "arguments/arguments.h"
#include "webserver/webserver.h"


int port = 8080;
string path = "./";

int main(int argc, char *argv[]) {
    ArgumentResult result = arguments(argc, argv);

    port = result.port;
    path = result.path;
    startServer(port, path);

    return 0;
}
