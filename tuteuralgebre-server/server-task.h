/*
 * server-task.h
 *
 * This is an interface for tasks to be made by the server
 *
 *  Created on: 29/gen/2016
 *      Author: mattia
 */

#ifndef SERVER_TASK_H_
#define SERVER_TASK_H_
#include "tcpstream.h"

/**
 * ServerTask is a functional interface used by th server to execute tasks in a multi-threaded fashion.
 */
class ServerTask{
public:
	/**
	 * This is the function to implement by concrete classes.
	 *
	 * execute() will contain the code to do the required task.
	 */
	virtual void execute() = 0;
	/**
	 * Destructor.
	 */
	virtual ~ServerTask() = 0;
};
/*
 * This way it's faster.
 */
inline ServerTask::~ServerTask() {}


#endif /* SERVER_TASK_H_ */
