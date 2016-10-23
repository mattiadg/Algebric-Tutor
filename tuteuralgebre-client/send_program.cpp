#include "send_program.h"
#include <iostream>
#include <fstream>

SendProgram::SendProgram(string name, string ip, int port) :
		MenuOption::MenuOption(name), _ip(ip), _port(port) {
}

SendProgram::~SendProgram() {
	//dtor
}

void SendProgram::execute() {
	char buffer[2];
	std::cout << "file to send: ";
	string filename;
	std::cin >> filename;
	std::ifstream istream(filename.c_str());
	if (!istream.good()) {
		throw 1; //Error in file reading
	}
	TCPStream* stream = connect();
	//Sends "Sending file..." to notify that is sending a file
	string message1 = "Sending file...";
	stream->send(message1.c_str(), message1.size());
	std::cout << message1 << std::endl;
	//Waiting for "ok"
	stream->receive(buffer, 2, 1);
	//Sending filename
	stream->send(filename.c_str(), filename.size());
	std::cout << "Sending filename: " << filename << endl;
	//Waiting for "ok"
	stream->receive(buffer, 2, 1);
	std::cout << string(buffer);
	if (string(buffer) == "ok") {
		while (getline(istream, message1)) {
			message1 += "\n";
			stream->send(message1.c_str(), message1.size());
		}
	}
	istream.close();
	stream->receive(buffer, 2, 1);
	std::cout << "file sent" << std::endl;
	delete stream;
}

TCPStream* SendProgram::connect() {
	TCPConnector* connector = new TCPConnector();
	TCPStream* stream = connector->connect(_ip.c_str(), _port);
	if (stream) {
		delete connector;
		return stream;
	} else {
		throw 2; //Socket error
	}
}
