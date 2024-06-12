#include <iostream>
#include <string>
#include <thread>
// This library doesn't work see why ?
// #include <mutex>
using namespace std;


// Use factory methods here to create different type of loggers info, debug, error

class Logger {
    static int ctr;
    static Logger *loggerInstance;
    static mutex mtx;
    Logger(){
        ctr++;
        cout << "Logger instance created. Total instances are: " << ctr << endl;
     };
    Logger(const Logger &);
    Logger operator=(const Logger &);
 public:
    static Logger * getLogger(){
        if(loggerInstance == nullptr){
            // mtx.lock();
            if(loggerInstance == nullptr){
                loggerInstance = new Logger();
            }
            // mtx.unlock();
        }


        return loggerInstance;
    }
     void log(string message){
        cout << message << endl;
     }
};


int Logger::ctr = 0;
Logger *Logger::loggerInstance = nullptr;


void user1Logs() {
    Logger * logger = Logger::getLogger();;
    logger->log("Hello from logger class user 1");
}

void user2Logs() {
    Logger * logger2 = Logger::getLogger();
    logger2->log("Hello from logger class user 2");
}



int main() {
    cout << "Hello from logger class" << endl;
    thread t1(user1Logs);
    // thread t2(user2Logs);

    t1.join();
    // t2.join();




    return 0;
}