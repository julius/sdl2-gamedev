#ifndef UTIL_LOGMANAGER_H
#define UTIL_LOGMANAGER_H

#include <iosfwd>
#include <string>


/**
 * LogManager class.
 *
 * Manages settings regarding log-levels, and log file name.
 *
 * @author SwarmingLogic
 */
class LogManager
{
public:
  enum LogLevel {
    LEVEL_DEBUG = 0,
    LEVEL_INFO,
    LEVEL_WARNING,
    LEVEL_ERROR,
    LEVEL_NONE
  };

  LogManager();

  LogManager(LogLevel fileLogLevel,
             LogLevel streamLogLevel);

  void log(LogLevel level,
           const std::string& loggerName,
           const std::string& message) const;

  virtual ~LogManager();

  LogLevel getFileLogLevel() const;
  void setFileLogLevel(LogLevel fileLogLevel);
  LogLevel getStreamLogLevel() const;
  void setStreamLogLevel(LogLevel streamLogLevel);
  const std::string& getLogfilePath() const;
  void setLogfilePath(std::string logfilePath);


private:
  void log2Stream(const std::string& formatted) const;
  void log2File(const std::string& formatted) const;

  static std::string logLevelAsString(LogLevel level);

  LogLevel fileLogLevel_;
  LogLevel streamLogLevel_;

  std::string logfilePath_;

  // NonCopyable
  LogManager(const LogManager& c);
  LogManager& operator=(const LogManager& c);
};

#endif
