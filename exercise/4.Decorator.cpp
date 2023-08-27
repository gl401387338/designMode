/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-26 11:21:39
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-26 12:35:43
 * @FilePath: \designMode\exercise\4.Decorator.cpp
 * @Description: 为了方便，没有分文件！
 * 装饰器模式，就用最经典的io例子来解释了
 * 当前需求：比如我现在有很多io操作，文件io，网络io，内存io等等
 * 他们的基本操作包括读，写，定位。但是除了基本操作外，还会有扩展
 * 诸如在读写定位前对数据进行加密，对数据保存缓冲区，或者两个同时
 * 进行等等。这时这些io流的扩展操作，就可以用装饰器来实现。
 * Copyright (c) 2023 by 毛利的野望, All Rights Reserved. 
 */
#include <iostream>

class Stream
{
public:
    virtual void read() = 0;

    virtual void seed() = 0;

    virtual void write() = 0; 
};

class FileStream : public Stream
{
public:
    void read() override
    {
        std::cout << "file stream read." << std::endl;
    }
    void seed() override
    {
        std::cout << "file stream seek." << std::endl;
    }
    void write() override
    {
        std::cout << "file stream write." << std::endl;
    }
};

class NetworkStream : public Stream
{
public:
    void read() override
    {
        std::cout << "network stream read." << std::endl;
    }
    void seed() override
    {
        std::cout << "network stream seek." << std::endl;
    }
    void write() override
    {
        std::cout << "network stream write." << std::endl;
    }
};

class MemoryStream : public Stream
{
public:
    void read() override
    {
        std::cout << "memory stream read." << std::endl;
    }
    void seed() override
    {
        std::cout << "memory stream seek." << std::endl;
    }
    void write() override
    {
        std::cout << "memory stream write." << std::endl;
    }
};

// decorator，扩展功能实现
class Decorator : public Stream
{
public:
    Stream* m_stream;

    Decorator(Stream* stream) : m_stream(stream) {}
};

class EncryptDecorator : public Decorator
{
public:
    EncryptDecorator(Stream* stream) : Decorator(stream) {}
    void read() override
    {
        std::cout << "encrypt..." << std::endl;
        m_stream->read();
    }
    void seed() override
    {
        std::cout << "encrypt..." << std::endl;
        m_stream->read();
    }
    void write() override
    {
        std::cout << "encrypt..." << std::endl;
        m_stream->read();
    }
};

class BufferDecorator : public Decorator
{
public:
    BufferDecorator(Stream* stream) : Decorator(stream) {}
    void read() override
    {
        std::cout << "save buffer..." << std::endl;
        m_stream->read();
    }
    void seed() override
    {
        std::cout << "save buffer..." << std::endl;
        m_stream->read();
    }
    void write() override
    {
        std::cout << "save buffer..." << std::endl;
        m_stream->read();
    } 
};



int main()
{
    FileStream* stream = new FileStream();
    BufferDecorator* buffer = new BufferDecorator(stream);
    EncryptDecorator* encrypt = new EncryptDecorator(buffer);
    encrypt->read();

    system("pause");
    return 0;
}