// Endless Online Awaken

#include "init.hpp"

#include "ping.hpp"
#include "login.hpp"
#include "account.hpp"
#include "../client.hpp"
#include "../gui.hpp"

#include <iostream>

namespace PacketHandlers::HInit
{
    void Main(sf::Packet &packet, std::array<intptr_t, 4> data_ptr)
    {
        Client client;
        unsigned char answer = 0;

        if(client.state != Client::State::Uninitialized) return;

        packet >> answer;

        if(answer == 1)
        {
            client.packet_handler.Register(PacketID::Ping, PacketHandlers::HPing::Main, data_ptr);
            client.packet_handler.Register(PacketID::Login, PacketHandlers::HLogin::Main, data_ptr);
            client.packet_handler.Register(PacketID::Account, PacketHandlers::HAccount::Main, data_ptr);
            client.state = Client::State::Initialized;

            std::cout << "Initialized." << std::endl;
        }
        if(answer == 2)
        {
            std::string message = "This client is outdated. Please update it and connect again.";

            GUI().OpenPopup("Server answer", message);
        }
    }
}
