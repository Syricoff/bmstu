#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

namespace SNS
{
    class StorageException : public std::exception
    {
    public:
        StorageException(const std::string &message) : message_(message) {}
        virtual const char *what() const noexcept override { return message_.c_str(); }

    private:
        std::string message_;
    };

    class CarException : public StorageException
    {
    public:
        CarException(const std::string &message) : StorageException(message) {}
    };

    class ClientException : public StorageException
    {
    public:
        ClientException(const std::string &message) : StorageException(message) {}
    };
}

#endif // EXCEPTION_H
