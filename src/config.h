#ifndef CONFIG_H
#define CONFIG_H
typedef char *string;
typedef int *
        bool;
#define true  (1==1)
#define false (!true)


typedef struct {
    int port;
    string path;
} ArgumentResult;

typedef struct {
    string header;
    int size
} SendData;
#endif
