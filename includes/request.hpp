#pragma once

#include  <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <netinet/in.h> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <map>
#include <vector>
#include <algorithm>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>

class Request {
    
    private:
        time_t      started;
        std::string request;
        std::string method;
        std::string path;
        std::string file;
        std::string query;
        bool        keepAlive;
        time_t      timeOut;
        std::string version;
        std::string host;
        std::string conn;
        std::string tr_enc;
        std::string body;
        std::map<std::string, std::string> headers;
        int         content_length;

    public:
        Request();
        Request(const Request &request);
        Request(const char* request);
        ~Request();
        Request &operator=(const Request &request);
        time_t getStarted();
        std::string getMethod() const;
        std::string getPath() const;

        std::string getVersion();
        std::string getHost();
        std::string getQuery() const;
        std::string getFile() const;
        time_t      getTimeOut();
        bool        getConn();
        void        clear();
        int         getContent_length();
        std::string getTr_enc();
        std::string getRequest();
        std::string getBody();
        std::map<std::string, std::string> const & getHeaders() const;

        void setStarted(time_t started);
        void setRequest(std::string request);
        void setBody(std::string body);

        void parseFirstLine(std::string &line);
        void ParseHeaders(std::istringstream &file);
};
