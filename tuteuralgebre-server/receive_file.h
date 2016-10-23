#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include "tcpstream.h"
#include "server-task.h"

/**
 * ReceiveFile implements the server's task of receiving and storing program files from the client.
 */
class ReceiveFile : public ServerTask
{
    public:
		/**
		 * Constructor.
		 *
		 * @param stream An open TCPStream to do communication with the client.
		 */
        ReceiveFile(TCPStream* stream);
        /**
         * Destructor.
         */
        virtual ~ReceiveFile();
        /**
         * Receive a file from the client.
         */
        virtual void execute();

    private:
        TCPStream* _stream;
};

#endif // RECEIVEFILE_H
