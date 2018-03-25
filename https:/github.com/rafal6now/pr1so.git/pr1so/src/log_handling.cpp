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

void log_omitted_synchronization(const int n, const int synct_time_minutes, const std::time_t last_update_time){
	std::tm * ptm = std::localtime(&last_update_time);
	char time_text[32];
	std::strftime(time_text, 32, "%Y-%m-%d %H:%M:%S", ptm);
	std::string msg = std::to_string(n) + "synchronization(s) omitted due to synchronization at " + std::string(time_text) + " taking more than " + std::to_string(synct_time_minutes) + " minute(s).";
	syslog(LOG_NOTICE, "%s", msg.c_str());
}

void log_synchronization(const int n_files, const int n_folders){
	std::string msg = std::to_string(n_files) + " file(s) and " + std::to_string(n_folders) + " updated.";
	syslog(LOG_INFO, "%s", msg.c_str());
}
