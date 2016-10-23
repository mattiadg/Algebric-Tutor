#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <thread>
#include "tcpacceptor.h"
#include "receive_file.h"
#include "retrieve_corrections.h"

/**
 * ServerTask* is the type of the classes which execute server's tasks.
 */
typedef ServerTask* task;

/**
 * A wrapper function which take a ServerTask* and call its method execute().
 * It's used to call these methods in a different thread.
 */
void execute_task(task);

/**
 * Accept connections in the provided ip address and port.
 * Dispatches valid request to task by means of execute_task() called in a new thread.
 */
int main(int argc, char** argv)
{
    if (argc < 2 || argc > 4)
    {
        printf("usage: server <port> [<ip>]\n");
        exit(1);
    }

    TCPStream* stream = NULL;
    TCPAcceptor* acceptor = NULL;
    if (argc == 3)
    {
        acceptor = new TCPAcceptor(atoi(argv[1]), argv[2]);
    }
    else
    {
        acceptor = new TCPAcceptor(atoi(argv[1]));
    }
    if (acceptor->start() == 0)
    {
        while (1)
        {
            stream = acceptor->accept();
            if (stream != NULL)
            {
                size_t len;
                char buffer[256];
                len = stream->receive(buffer, sizeof(buffer));
                buffer[len] = '\0';
                std::cout << buffer << std::endl;
                if(len > 0)
                {
                	task toExecute;
                	std::cout << string(buffer) << std::endl;
                    if(string(buffer) == string("Sending file..."))
                    {
                    	stream->send("ok", 2);
						std::cout << "Calling ReceiveFile" << std::endl;
                        toExecute = new ReceiveFile(stream);

                    } else if(string(buffer) == string("Retrieve corrections")) {
						std::cout << "Calling RetrieveCorrections" << std::endl;
						toExecute = new RetrieveCorrections(stream);
					} else {
						delete stream;
						continue;
					}
                    std::thread t(execute_task, toExecute);
                    t.detach();
                }
            }
        }
    }
}

void execute_task(task toExe){
	toExe->execute();
	delete toExe;
}
