#include "receive_file.h"
#include <iostream>
#include <fstream>

ReceiveFile::ReceiveFile(TCPStream* stream)
:_stream(stream)
{}

ReceiveFile::~ReceiveFile()
{
}

void ReceiveFile::execute()
{
	size_t len;
	char buffer[256];
	//receive filename
	len = _stream->receive(buffer, sizeof(buffer), 1);
	buffer[len] = '\0';
	std::cout << buffer << std::endl;
	if(len > 0)
	{
		_stream->send("ok", 2);
		std::ofstream ostream;
		string filename = "received/" + string(buffer);
		ostream.open(filename);
		while ((len = _stream->receive(buffer, sizeof(buffer) - 1, 1)) > 0)
		{
			buffer[len] = '\0';
			ostream << buffer;
			std::cout << buffer;
		}
		ostream.close();
		std::cout << "ostream closed" << std::endl;
		_stream->send("ok", 2);
		std::cout << "ok sent" << std::endl;
	}
	delete _stream;
}


