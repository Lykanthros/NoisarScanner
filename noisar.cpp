#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    std::string target_ip;
    int start_port, end_port;

    std::cout << "Enter the target IP address: ";
    std::cin >> target_ip;

    std::cout << "Enter the starting port: ";
    std::cin >> start_port;

    std::cout << "Enter the ending port: ";
    std::cin >> end_port;

    for (int port = start_port; port <= end_port; ++port) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, target_ip.c_str(), &(target.sin_addr));

        if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
            std::cout << "Port " << port << " is open" << std::endl;
        }

        close(sock);
    }

    return 0;
}
