#ifndef __XTC__INTE_ADDRESS__H
#define __XTC__INTE_ADDRESS__H

#include <string>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

namespace xtc{

// IPV4 only
class InetAddress {
public:
  InetAddress() = default;
  InetAddress(std::string const& address, uint16_t port);
  ~InetAddress() = default;

  uint16_t const& Getport() const { return addr_.sin_port;}
  std::string Getaddress() const { return std::string(inet_ntoa(addr_.sin_addr)) ;}
  sa_family_t Getfamily() const { return addr_.sin_family; }
  
  sockaddr_in const& Getaddr() const { return addr_;}

private:
  union {
    struct sockaddr_in addr_;
    struct sockaddr_in6 addr6_;
  };
};



} // namespace xtc

#endif
