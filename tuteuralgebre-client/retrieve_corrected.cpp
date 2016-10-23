/*
 * retrieve_corrected.cpp
 *
 *  Created on: 28/gen/2016
 *      Author: mattia
 */

#include "retrieve_corrected.h"
#include "tcpconnector.h"
#include <fstream>
#include <iostream>

RetrieveCorrected::RetrieveCorrected(string name, string ip, int port) :
		MenuOption::MenuOption(name), _ip(ip), _port(port) {
}

RetrieveCorrected::~RetrieveCorrected() {
}

void RetrieveCorrected::execute() {
	string welcome_message = "Retrieve corrections";
	string ack_message = "Sending corrections...";
	TCPConnector* connector = new TCPConnector();
	TCPStream* stream = connector->connect(_ip.c_str(), _port);
	char buffer[1024];
	if (stream) {
		delete connector;
	} else {
		throw 2; //Socket error
	}
	//Request corrections to server
	stream->send(welcome_message.c_str(), welcome_message.length());
	//Waiting ack
	int len = stream->receive(buffer, ack_message.length());
	//if ack is correct, let's wait for the corrections
	buffer[len] = '\0';
	if (string(buffer) == ack_message) {
		std::cout << "Available files:" << std::endl;
		while ((len = stream->receive(buffer, sizeof(buffer), 1)) > 0) {
			buffer[len] = '\0';
			std::cout << string(buffer);
		}
		std::cout << "File to retrieve: ";
		string filename;
		std::cin >> filename;
		stream->send(filename.c_str(), filename.length());
		//Receive file
		std::ofstream ostream;
		ostream.open(string("corrected/" + filename).c_str());
		while ((len = stream->receive(buffer, sizeof(buffer), 1)) > 0) {
			buffer[len] = '\0';
			std::cout << buffer;
			ostream << buffer;
		}
		ostream.close();
		stream->send("ok", 2);
		delete stream;
	}
}

