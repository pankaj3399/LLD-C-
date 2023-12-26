#include <iostream>
#include <string>

using namespace std;

class LogProcessor
{
public:
    static int const INFO = 1;
    static int const DEBUG = 2;
    static int const ERROR = 3;
    LogProcessor *nextLogProcessor;
    LogProcessor(LogProcessor *next)
    {
        nextLogProcessor = next;
    }

    virtual void log(int logLevel, string const &message)
    {
        if (nextLogProcessor != nullptr)
        {
            nextLogProcessor->log(logLevel, message);
        }
        else
        {
            cout << "Not working code" << endl;
        }
    }
};

class DebugLogProcessor : public LogProcessor
{
public:
    DebugLogProcessor(LogProcessor *next) : LogProcessor(next) {}

    void log(int logLevel, string const &message)
    {
        if (logLevel == DEBUG)
        {
            cout << "DEBUG: " << message << endl;
        }
        else
        {
            LogProcessor::log(logLevel, message);
        }
    }
};

class InfoLogProcessor : public LogProcessor
{
public:
    InfoLogProcessor(LogProcessor *next) : LogProcessor(next) {}

    void log(int logLevel, string const &message)
    {
        if (logLevel == INFO)
        {
            cout << "INFO: " << message << endl;
        }
        else
        {
            LogProcessor::log(logLevel, message);
        }
    }
};

class ErrorLogProcessor : public LogProcessor
{
public:
    ErrorLogProcessor(LogProcessor *next) : LogProcessor(next) {}

    void log(int logLevel, string const &message)
    {
        if (logLevel == ERROR)
        {
            cout << "ERROR: " << message << endl;
        }
        else
        {
            LogProcessor::log(logLevel, message);
        }
    }
};

int main()
{
    LogProcessor *logObject = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(nullptr)));
    logObject->log(logObject->INFO, "Value is");
    logObject->log(logObject->DEBUG, "Debugging");
    logObject->log(logObject->ERROR, "This is the error");
    return 0;
}