#ifndef SENDPROGRAM_H
#define SENDPROGRAM_H

#include "menu_option.h"
#include "tcpconnector.h"
#include <string>

/**
 * \brief SendProgram is used to send an exercise to the server, so that the teacher can correct it.
 *
 * It's an implementation of MenuOption, so it's one of the functionality added to the client with the Command Pattern provided
 * by ClientMenu.
 */
class SendProgram : public MenuOption
{
    public:
		/**
		 * Constructor.
		 *
		 * @param name The string to print in the menu
		 * @param ip The ip address of the server
		 * @param port The listening port of the server
		 */
        SendProgram(string name, string ip, int port);
        /**
         * Destructor.
         */
        virtual ~SendProgram();

        /**
         * Implements MenuOption::execute().
         *
         * It contacts the send to it a file prompted by the user.
         */
        virtual void execute();
    private:
        std::ifstream requestFile();
        TCPStream* connect();
        string _ip;
        int _port;
};

#endif // SENDPROGRAM_H
