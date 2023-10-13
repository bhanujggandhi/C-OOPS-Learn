#include <bits/stdc++.h>
using namespace std;

class Logger {
   protected:
    Logger *next;

   public:
    Logger(Logger *next) {
        this->next = next;
    }

    virtual void logMessage(int level, string &message) = 0;

    void setNextLogger(Logger *next) {
        this->next = next;
    }
};

class ConsoleLogger : public Logger {
   private:
    const static int INFO = 1;

   public:
    ConsoleLogger(Logger *nextLogger) : Logger(nextLogger) {
    }

    void logMessage(int level, string &message) {
        if (level == INFO) {
            cout << "Console Logger: " << message << endl;
        } else {
            if (next != nullptr) {
                next->logMessage(level, message);
            }
        }
    }
};

class FileLogger : public Logger {
   private:
    const static int WARNING = 2;

   public:
    FileLogger(Logger *nextLogger) : Logger(nextLogger) {
    }

    void logMessage(int level, string &message) {
        if (level == WARNING) {
            cout << "File Logger: " << message << endl;
        } else {
            if (next != nullptr) {
                next->logMessage(level, message);
            }
        }
    }
};

class ErrorLogger : public Logger {
   private:
    const static int ERROR = 3;

   public:
    ErrorLogger(Logger *nextLogger) : Logger(nextLogger) {
    }

    void logMessage(int level, string &message) {
        if (level == ERROR) {
            cout << "Error Logger: " << message << endl;
        } else {
            if (next != nullptr) {
                next->logMessage(level, message);
            }
        }
    }
};

int main() {
    Logger *errorLogger = new ErrorLogger(nullptr);
    Logger *fileLogger = new FileLogger(errorLogger);
    Logger *consoleLogger = new ConsoleLogger(fileLogger);

    string message = "This is an informational message";
    consoleLogger->logMessage(1, message);

    return 0;
}

/*
In this example:

Logger is the abstract handler class with a reference to the next logger in the chain. It defines the logMessage method.

ConsoleLogger, FileLogger, and ErrorLogger are concrete handlers that implement the logMessage method and decide whether to process the log message based on the log level.

In the main function, we create a chain of loggers where each logger passes the log message to the next logger in the chain if it doesn't handle the message.
*/