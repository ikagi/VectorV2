#include <iostream>
#include <asio.hpp>

int main() {
    asio::io_context io;
    
    asio::serial_port serial(io);
    serial.open("/dev/ttyUSB0");  // Change this to your serial port on Linux
    serial.set_option(asio::serial_port_base::baud_rate(9600));
    serial.set_option(asio::serial_port_base::character_size(8));
    serial.set_option(asio::serial_port_base::parity(asio::serial_port_base::parity::none));
    serial.set_option(asio::serial_port_base::stop_bits(asio::serial_port_base::stop_bits::one));

    char data;

    while (true) {
        asio::read(serial, asio::buffer(&data, 1));
        std::cout << data; // Process the received data as needed
    }

    return 0;
}