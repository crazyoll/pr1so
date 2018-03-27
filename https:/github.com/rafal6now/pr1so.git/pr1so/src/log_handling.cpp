#include "log_handling.hpp"


void open_log(){
	openlog("File synchronizer", LOG_CONS, LOG_DAEMON); //if *ident is NULL, program name will be used
}

void log_start(){
	syslog(LOG_INFO, "%s", "Program started");
}

void log_exit(){
	syslog(LOG_NOTICE, "%s", "Program killed");
}

void sigquit_handler(int signum){
	log_exit();
	closelog();
}

void set_sigquit_with_log(){
	signal(SIGQUIT, sigquit_handler);
}

void log_success(std::string msg){
	syslog(LOG_INFO, "%s", msg.c_str());
}

void log_failiure(std::string msg){
	syslog(LOG_ERR, "%s", msg.c_str());
}

void log_critical_failure(std::string msg){
	syslog(LOG_CRIT, "%s", msg.c_str());
}
