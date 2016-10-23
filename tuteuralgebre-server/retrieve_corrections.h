#ifndef RETRIEVECORRECTIONS_H
#define RETRIEVECORRECTIONS_H

#include "tcpstream.h"
#include "server-task.h"

/**
 * RetrieveCorrections is a server's task whose aim is to let the client to download a file among the corrected ones.
 */
class RetrieveCorrections : public ServerTask
{
    public:
		/**
		 * Constructor.
		 *
		 * @param stream An open stream to communicate with the client.
		 */
        RetrieveCorrections(TCPStream* stream);
        /**
         * Destructor.
         */
        virtual ~RetrieveCorrections();
        /**
         * Executes the task of showing the files to the client and let it to download one.
         */
        virtual void execute();

    private:
        TCPStream* _stream;
};

#endif // RETRIEVECORRECTIONS_H
