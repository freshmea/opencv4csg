//#include "Poco/Timer.h"
//#include "Poco/Thread.h"
//#include "Poco/Stopwatch.h"
//#include <iostream>
//
///*
// * Main application
// */
//
//class PocoTimer
//{
//public:
//    //------------
//    PocoTimer() { stopWatch.start(); }
//    //------------
//    void PrintElapsedTime(Poco::Timer& timer)
//    {
//        std::cout << "Time elapsed: " << stopWatch.elapsed() / 1000 << " milliseconds." << std::endl;
//    }
//private:
//    Poco::Stopwatch stopWatch;
//};
//
//
//int main() {
//
//    PocoTimer pocoTimer;
//    Poco::Timer timer(250, 500);
//// -- print command -- //
//    timer.start(Poco::TimerCallback<PocoTimer>(pocoTimer, &PocoTimer::PrintElapsedTime));
//    Poco::Thread::sleep(5000);
//    timer.stop();
//
//}

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include <string>
#include <vector>

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

class MyRequestHandler : public HTTPRequestHandler
{
public:
    virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
    {
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType("text/html");

        ostream& out = resp.send();
        out << "<h1>Hello world!</h1>"
            << "<p>Count: "  << ++count         << "</p>"
            << "<p>Host: "   << req.getHost()   << "</p>"
            << "<p>Method: " << req.getMethod() << "</p>"
            << "<p>URI: "    << req.getURI()    << "</p>";
        out.flush();

        cout << endl
             << "Response sent for count=" << count
             << " and URI=" << req.getURI() << endl;
    }

private:
    static int count;
};

int MyRequestHandler::count = 0;

class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
    virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &)
    {
        return new MyRequestHandler;
    }
};

class MyServerApp : public ServerApplication
{
protected:
    int main(const vector<string> &)
    {
        HTTPServer s(new MyRequestHandlerFactory, ServerSocket(9090), new HTTPServerParams);

        s.start();
        cout << endl << "Server started" << endl;

        waitForTerminationRequest();  // wait for CTRL-C or kill

        cout << endl << "Shutting down..." << endl;
        s.stop();

        return Application::EXIT_OK;
    }
};

int main(int argc, char** argv)
{
    MyServerApp app;
    return app.run(argc, argv);
}