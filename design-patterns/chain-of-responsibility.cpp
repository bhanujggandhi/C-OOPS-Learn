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
    const static int INFO = 2;

   public:
    FileLogger(Logger *nextLogger) : Logger(nextLogger) {
    }

    void logMessage(int level, string &message) {
        if (level == INFO) {
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
    const static int INFO = 3;

   public:
    ErrorLogger(Logger *nextLogger) : Logger(nextLogger) {
    }

    void logMessage(int level, string &message) {
        if (level == INFO) {
            cout << "Error Logger: " << message << endl;
        } else {
            if (next != nullptr) {
                next->logMessage(level, message);
            }
        }
    }
};

int main() {
    Logger *consoleLogger = new ConsoleLogger(nullptr);
    Logger *fileLogger = new FileLogger(consoleLogger);
    Logger *errorLogger = new ErrorLogger(fileLogger);

    string message = "This is an informational message";
    errorLogger->logMessage(3, message);

    return 0;
}