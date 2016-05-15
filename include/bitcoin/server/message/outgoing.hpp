/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-server.
 *
 * libbitcoin-server is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_SERVER_OUTGOING
#define LIBBITCOIN_SERVER_OUTGOING

#include <cstdint>
#include <string>
#include <bitcoin/protocol.hpp>
#include <bitcoin/server/define.hpp>
#include <bitcoin/server/message/incoming.hpp>

namespace libbitcoin {
namespace server {

class BCS_API outgoing
{
public:
    /// Default constructor provided for containers and copying.
    outgoing();

    /// Parse the incoming request and retain the outgoing data.
    outgoing(const incoming& request, const data_chunk& data);

    /// Empty destination is interpreted as an unspecified destination.
    outgoing(const std::string& command, const data_chunk& data,
        const data_chunk& destination);

    void send(protocol::zmq::socket& socket) const;

    uint32_t id() const;
    const data_chunk& data() const;
    const std::string& command() const;
    const data_chunk destination() const;

private:
    uint32_t id_;
    data_chunk data_;
    std::string command_;
    data_chunk destination_;
};

typedef std::function<void(const outgoing&)> send_handler;

} // namespace server
} // namespace libbitcoin

#endif