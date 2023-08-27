/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-26 11:21:39
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-26 12:35:43
 * @FilePath: \designMode\exercise\4.Decorator.cpp
 * @Description: Ϊ�˷��㣬û�з��ļ���
 * װ����ģʽ����������io������������
 * ��ǰ���󣺱����������кܶ�io�������ļ�io������io���ڴ�io�ȵ�
 * ���ǵĻ���������������д����λ�����ǳ��˻��������⣬��������չ
 * �����ڶ�д��λǰ�����ݽ��м��ܣ������ݱ��滺��������������ͬʱ
 * ���еȵȡ���ʱ��Щio������չ�������Ϳ�����װ������ʵ�֡�
 * Copyright (c) 2023 by ë����Ұ��, All Rights Reserved. 
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

// decorator����չ����ʵ��
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