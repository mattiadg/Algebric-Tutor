#include "retrieve_corrections.h"
#include "dirent.h"
#include <boost/filesystem.hpp>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include <iostream>
#include <fstream>
#define BOOST_FILESYSTEM_NO_DEPRECATED

using namespace std;
using namespace boost::filesystem;

RetrieveCorrections::RetrieveCorrections(TCPStream* stream) :
		_stream(stream) {
	//ctor
}

RetrieveCorrections::~RetrieveCorrections() {
	//dtor
}

void RetrieveCorrections::execute() {
	char buffer[1024];
	string ack_message = "Sending corrections...";
	_stream->send(ack_message.c_str(), ack_message.length());
	path p("corrections");
	//Open directory and error checking
	for (auto i = directory_iterator(p); i != directory_iterator(); i++) {
		if (!is_directory(i->path())) { //we eliminate directories in a list
			string filename = i->path().filename().string() + "\n";
			cout << filename << endl;
			_stream->send(filename.c_str(), filename.length());
		} else
			continue;
	}
	std::cout << "directory closed" << endl;
	//WAIT FOR FILE REQUEST
	int len = _stream->receive(buffer, sizeof(buffer));
	buffer[len] = '\0';
	//Open file
	std::ifstream istream(p.filename().string() + "/" + buffer);
	if (!istream.good()) {
		throw 1; //Error while opening file
	}
	//Reading and sending file
	string message_buf;
	while (getline(istream, message_buf)) {
		message_buf += "\n";
		_stream->send(message_buf.c_str(), message_buf.length());
	}
	//Waiting for "ok"
	_stream->receive(buffer, 2);
	delete _stream;
}
