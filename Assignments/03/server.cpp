#include <thread>
#include <iostream>

// These are custom classes that encode the web transactions.  They're
//   actually quite simple (mostly because we're solving a very limited)
//   problem.
#include "Connection.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"

// This is the unique networking "port" that your web server is communicating
//   with the web browser with.  Make sure to use you're unique port, otherwise
//   you'll stomp on other people trying to do the same thing.
//
// Common ports, particularly for this web and related stuff are:
//   - 22 : ssh port
//   - 25 : email port
//   - 80 : http port (unencrypted web connection)
//   - 8080 : https port (encrypted web connection)
//
//  (Don't use any of them.  Generally, above 9000 is usually pretty clear)
//
const uint16_t DefaultPort = 8120; // Update this variable with your assigned port value

int main(int argc, char* argv[]) {
    uint16_t port = argc > 1 ? std::stol(argv[1]) : DefaultPort;

    // Opens a connection on the given port.  With a suitable URL
    //
    //     http://<hostname>:<port> (e.g., http://blue.cs.sonoma.edu:8000)
    //
    //    this will set up networking socket at the given port, and wait
    //    for another application (like a web browser) to start a
    //    conversation.
    //
    // When you connect from your web browser, use your unique port value
    //   after the color (:) in the URL.
    Connection connection(port);

    // Process sessions.  A session begins with a web browser making a
    //   request.  When the request is made, our connection "accepts"
    //   the connection, and starts a session.
    while (connection) {

        // A session is composed of a bunch of requests (from the "client",
        //   like a web browser), and responses from us, the web "server".
        //   Each request is merely an ASCII string (with some special
        //   characters specially encoded.  We don't implement all that
        //   fancy stuff here.  We're keeping it simple).
        Session session(connection.accept());

        // A message received from the client will be a string like
        //
        //      GET <filename> HTTP/1.1 [plus a bunch of optional stuff]
        //
        //    Here, we merely read that string from the socket into
        //    a string.
        std::string msg;
        session >> msg;

        // However, if our msg has requests in it, we send it to a
        //   request parser, HTTPRequest.  The resulting request
        //   contains the type of request, the filename, and other
        //   information.
	std::thread{[&]() {
            HTTPRequest request(msg);
            const char *root = "/home/faculty/shreiner/public_html/03";
            HTTPResponse response(request, root);
            session << response;
        }}.detach();
    }
}

