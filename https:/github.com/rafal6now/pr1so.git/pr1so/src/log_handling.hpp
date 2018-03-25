/*
 * log_handling.hpp
 *
 *  Created on: Mar 25, 2018
 *      Author: so
 */

#ifndef LOG_HANDLING_HPP
#define LOG_HANDLING_HPP

#include <string>
#include <ctime>
#include <syslog.h>
#include <signal.h>

void open_log();
void log_start();
void log_exit();
void sigquit_handler(int signum);
void set_sigquit_with_log();
void log_omitted_synchronization(const int n, const int synct_time_minutes, const std::time_t last_update_time);


#endif /* LOG_HANDLING_HPP */
