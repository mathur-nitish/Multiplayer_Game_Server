#include <iostream>
#include <asio.hpp>  // standalone Asio include

using asio::ip::tcp;

int main() {
    try {
        asio::io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));

        std::cout << "Server started. Listening on port 8080..." << std::endl;

        for (;;) {
            tcp::socket socket(io);
            acceptor.accept(socket);

            std::string msg = "Hello from GameServer!\n";
            asio::write(socket, asio::buffer(msg));
        }
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
