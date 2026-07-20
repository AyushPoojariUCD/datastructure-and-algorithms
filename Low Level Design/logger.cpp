#include <iostream>
#include <memory>

using namespace std;

//===================== ENUM =====================//

enum class LogLevel {
    INFO,
    DEBUG,
    WARNING,
    ERROR
};

//===================== INTERFACE =====================//

class LogAppender {
public:
    virtual void append(LogLevel level, const string& message) = 0;
    virtual ~LogAppender() {}
};

//===================== CONSOLE APPENDER =====================//

class ConsoleAppender : public LogAppender {

private:

    string levelToString(LogLevel level) {

        switch(level) {

            case LogLevel::INFO:
                return "INFO";

            case LogLevel::DEBUG:
                return "DEBUG";

            case LogLevel::WARNING:
                return "WARNING";

            case LogLevel::ERROR:
                return "ERROR";
        }

        return "";
    }

public:

    void append(LogLevel level,
                const string& message) override {

        cout << "[" << levelToString(level)
             << "] "
             << message
             << endl;
    }
};

//===================== LOGGER =====================//

class Logger {

private:

    unique_ptr<LogAppender> appender;

    Logger() {
        appender = make_unique<ConsoleAppender>();
    }

public:

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {

        static Logger logger;
        return logger;
    }

    void log(LogLevel level,
             const string& message) {

        appender->append(level, message);
    }
};

//===================== MAIN =====================//

int main() {

    Logger& logger = Logger::getInstance();

    logger.log(LogLevel::INFO,
               "Application Started");

    logger.log(LogLevel::DEBUG,
               "Fetching User");

    logger.log(LogLevel::WARNING,
               "Memory Usage High");

    logger.log(LogLevel::ERROR,
               "Database Connection Failed");

    return 0;
}
