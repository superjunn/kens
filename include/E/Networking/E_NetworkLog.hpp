/**
 * @file   E_NetworkLog.hpp
 * @Author leeopop (dlrmsghd@gmail.com)
 * @date   November, 2014
 * @brief  Header for E::NetworkLog
 */

#ifndef E_NETWORKLOG_HPP_
#define E_NETWORKLOG_HPP_

#include <E/E_Common.hpp>

namespace E {
/**
 * @brief Log provides log-related utilities for network modules.
 * We recommend you to inherit this class privately to a network module,
 * and it will enable NetworkLog::print_log in your namespace.
 *
 * @note You cannot use both Log and NetworkLog simultaneously.
 * @see E::Log
 */
class System;
class NetworkLog {
private:
  uint64_t level;
  System &system;

public:
  /**
   * @brief Constructs a NetworkLog instance.
   *
   * @param system System
   */
  NetworkLog(System &system);
  /**
   * @brief Constructs a NetworkLog instance with log level.
   *
   * @param system System
   * @param level log level
   */
  NetworkLog(System &system, uint64_t level);
  /**
   * @brief Destructs a NetworkLog instance.
   *
   */
  ~NetworkLog();

  /**
   * @brief Enumerations for log levels.
   *
   */
  enum LOG_LEVEL {
    PACKET_TO_MODULE = 0UL,
    PACKET_FROM_MODULE,
    PACKET_TO_HOST,
    PACKET_FROM_HOST,
    PACKET_ALLOC,
    PACKET_CLONE,
    PACKET_FREE,
    PACKET_QUEUE,
    PACKET_DROPPED,
    SYSCALL_RAISED,
    SYSCALL_FINISHED,
    SYSCALL_BLOCKED,
    SYSCALL_UNBLOCKED,
    SYSCALL_ERROR,
    APPLICATION_RETRUN,
    MODULE_ERROR,
    PROTOCOL_ERROR,
    PROTOCOL_WARNING,
    TCP_LOG,
    LEVEL_COUNT,
  };
  /**
   * @brief Prints log with specified log level and format.
   * NetworkLog::print_log prints logs specified in log level parameter.
   * For example, if log level is set to TCP_LOG, it only prints TCP_LOG logs.
   * If you want to print multiple log levels in NetworkLog,
   * you can set log level with OR operation (i.e.  SYSCALL_ERROR |
   * MODULE_ERROR).
   *
   * @note Log::print_log
   *
   * @param level log level
   * @param format Format string
   * @param ... Print arguments for format string
   *
   */
  void print_log(uint64_t level, const char *format, ...)
#ifdef HAVE_ATTR_FORMAT
      __attribute__((format(printf, 3, 4)))
#endif
      ;

  /**
   * @brief Prints log with specified log level and format.
   * NetworkLog::print_log prints logs specified in log level parameter.
   * For example, if log level is set to TCP_LOG, it only prints TCP_LOG logs.
   * If you want to print multiple log levels in NetworkLog,
   * you can set log level with OR operation (i.e.  SYSCALL_ERROR |
   * MODULE_ERROR).
   *
   * @note Log::print_log
   *
   * @param level log level
   * @param format Format string
   * @param args Print arguments for format string
   *
   */
  void vprint_log(uint64_t level, const char *format, va_list args);

public:
  /**
   * @brief Default log level.
   *
   */
  static uint64_t defaultLevel;
};

} // namespace E

#endif /* E_NETWORKLOG_HPP_ */
