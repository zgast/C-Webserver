cmake_minimum_required(VERSION 3.20)
project(Webserver C)

set(CMAKE_C_STANDARD 11)

add_executable(Webserver ../Webserver/src/main.c ../Webserver/src/arguments/arguments.h ../Webserver/src/arguments/arguments.c ../Webserver/src/config.h ../Webserver/src/utils/logger.c ../Webserver/src/utils/logger.h ../Webserver/src/webserver/webserver.c ../Webserver/src/webserver/webserver.h ../Webserver/src/file/file.c ../Webserver/src/file/file.h ../Webserver/src/file/contentTypes.h)
