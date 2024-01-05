// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/ftp_server/ftp_server.proto)

#include <iomanip>

#include "ftp_server_impl.h"
#include "plugins/ftp_server/ftp_server.h"

namespace mavsdk {





FtpServer::FtpServer(std::shared_ptr<ServerComponent> server_component) : ServerPluginBase(), _impl{std::make_unique<FtpServerImpl>(server_component)} {}


FtpServer::~FtpServer() {}





FtpServer::Result FtpServer::set_root_dir(std::string path) const
{
    return _impl->set_root_dir(path);
}




std::ostream& operator<<(std::ostream& str, FtpServer::Result const& result)
{
    switch (result) {
        case FtpServer::Result::Unknown:
            return str << "Unknown";
        case FtpServer::Result::Success:
            return str << "Success";
        case FtpServer::Result::DoesNotExist:
            return str << "Does Not Exist";
        case FtpServer::Result::Busy:
            return str << "Busy";
        default:
            return str << "Unknown";
    }
}




} // namespace mavsdk