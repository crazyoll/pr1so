/*
 * log_handling.hpp
 *
 *  Created on: Mar 25, 2018
 *      Author: so
 */

#ifndef LOG_HANDLING_HPP_
#define LOG_HANDLING_HPP_

#include <string>
#include <ctime>
#include <syslog.h>
#include <signal.h>

void open_log();
void log_start();
void log_exit();
void log_success(std::string msg);
void log_failiure(std::string msg);
void log_critical_failure(std::string msg);

void set_sigquit_with_log();

#endif /* LOG_HANDLING_HPP_ */
