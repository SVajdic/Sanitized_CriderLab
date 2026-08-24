#ifndef LOGGER_SETUP_H
#define LOGGER_SETUP_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-04-22
 * LAST EDIT: 2025-04-24
 *
 * Generic Use Code 
 *
 * Header file for using a logger and clog instead of cout
 * 
 **********************************************************************/
#include <fstream>

static std::ofstream g_log_file;  // one global

inline void init_logging(const std::string& path) {
    g_log_file.open(path, std::ios::out|std::ios::trunc);
    if (!g_log_file.is_open()) {
        throw std::runtime_error("Cannot open log file: " + path);
    }
    std::clog.rdbuf(g_log_file.rdbuf());  // redirect clog

    return;
}

#endif
