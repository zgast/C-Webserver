//
// Created by markus on 11.11.21.
//

#ifndef WEBSERVER_CONTENTTYPES_H
#define WEBSERVER_CONTENTTYPES_H

typedef struct {
    string ending;
    string header;
} ContentTypes;

const ContentTypes contentTypes[] = {
        {".html", "text/html"},
        {".json", "application/json"},
        {".png",  "image/png"},
        {".jpg",  "image/jpeg"},
        {".jpeg", "image/jpeg"},
        {".svg",  "image/svg+xml"},
        {".gif",  "image/gif"},
        {".css",  "text/css"},
        {".xml",  "application/xml"},
        {".pdf",  "application/pdf"},
        {".js",   "application/javascript"},
};


#endif //WEBSERVER_CONTENTTYPES_H
