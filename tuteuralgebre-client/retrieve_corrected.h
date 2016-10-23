/*
 * retrieve_corrected.h
 *
 *  Created on: 28/gen/2016
 *      Author: mattia
 */

#ifndef RETRIEVE_CORRECTED_H_
#define RETRIEVE_CORRECTED_H_

#include "menu_option.h"
#include <string>

/**
 * \brief RetrieveCorrected creates a client which ask to the server process the list of corrected exercises and allows the user to
 * download one of them.
 */
class RetrieveCorrected: public MenuOption {
public:
	/**
	 * Constructor.
	 *
	 * @param name The string printed in the menu
	 * @param ip The ip address of the server
	 * @param port The listening port of the server
	 */
	RetrieveCorrected(string name, string ip, int port);
	/**
	 * Destructor.
	 */
	~RetrieveCorrected();
	/**
	 * Connect to the server, show the list of files to the user and allows to download one of them.
	 */
	virtual void execute();

private:
	string _ip;
	int _port;
};

#endif /* RETRIEVE_CORRECTED_H_ */
