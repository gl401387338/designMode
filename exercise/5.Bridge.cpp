/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-27 11:06:31
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-27 11:47:00
 * @FilePath: \designMode\exercise\5.Bridge.cpp
 * @Description: 为了方便，没有分文件！
 * 首先假设一个符合桥模式的（2个或以上维度的变化）需求：2个维度吧！
 * 设计一个软件，首先它包含很多接口，如启动，登录，发送信息；以及
 * 显示控件，播放音乐等等。而对不不同平台，显示控件和播放音乐的方式
 * 是不一样的（如pc和安卓显示和播放代码不同），对于不同软件版本，
 * 启动登录发送信息也是不一样的（如普通版啥也没有，会员版会显示不同
 * 图案，播放不同音效等等）。两个维度的变化。
 * 
 * Copyright (c) 2023 by 毛利的野望, All Rights Reserved. 
 */
// 析构的虚函数，不能 = 0，必须有函数体！！！


#include <iostream>

class PlatformFeature;

class Software
{
public:
    PlatformFeature* m_platformFeature;
public:
    Software(PlatformFeature* platformFeature) : m_platformFeature(platformFeature) {}
    virtual ~Software() {} // 析构的虚函数，不能 = 0，必须有函数体！！！

    virtual void run() = 0;
    virtual void login() = 0;
    virtual void sendMessage() = 0;
};

class PlatformFeature
{
public:     
    virtual void showPicture() = 0;
    virtual void playRadio() = 0;
};

//各种平台功能实现
class PCPlatformFeature : public PlatformFeature
{
public:
    void showPicture() override
    {
        std::cout << "pc端开始显示图片" << std::endl;
    }
    void playRadio() override
    {
        std::cout << "pc端开始播放音效" << std::endl;
    }
};

class AndroidPlatformFeature : public PlatformFeature
{
public:
    void showPicture() override
    {
        std::cout << "android端开始显示图片" << std::endl;
    }
    void playRadio() override
    {
        std::cout << "android端开始播放音效" << std::endl;
    }
};

class IOSPlatformFeature : public PlatformFeature
{
public:
    void showPicture() override
    {
        std::cout << "ios端开始显示图片" << std::endl;
    }
    void playRadio() override
    {
        std::cout << "ios端开始播放音效" << std::endl;
    }
};

//各种版本功能实现
class NormalVersionSoftware : public Software
{
public:
    NormalVersionSoftware(PlatformFeature* platformFeature) : Software(platformFeature) {}
    ~NormalVersionSoftware() override { std::cout; }

    void run() override
    {
        std::cout << "软件启动！" << std::endl;
    }
    void login() override
    {
        std::cout << "软件登录！" << std::endl;
    }
    void sendMessage() override
    {
        std::cout << "你已上线！" << std::endl;
    }
};

class VIPVersionSoftware : public Software
{
public:
    VIPVersionSoftware(PlatformFeature* platformFeature) : Software(platformFeature) {}
    ~VIPVersionSoftware() override { std::cout; }

    void run() override
    {
        m_platformFeature->showPicture();
        std::cout << "软件启动！" << std::endl;
    }
    void login() override
    {
        m_platformFeature->showPicture();
        std::cout << "软件登录！" << std::endl;
    }
    void sendMessage() override
    {
        m_platformFeature->showPicture();
        std::cout << "您已上线！" << std::endl;
    }
};

class SuperVIPVersionSoftware : public Software
{
public:
    SuperVIPVersionSoftware(PlatformFeature* platformFeature) : Software(platformFeature) {}
    ~SuperVIPVersionSoftware() override { std::cout; }

    void run() override
    {
        m_platformFeature->showPicture();
        m_platformFeature->playRadio();
        std::cout << "软件启动！" << std::endl;
    }
    void login() override
    {
        m_platformFeature->showPicture();
        m_platformFeature->playRadio();
        std::cout << "软件登录！" << std::endl;
    }
    void sendMessage() override
    {
        m_platformFeature->showPicture();
        m_platformFeature->playRadio();
        std::cout << "您已上线啦，尊敬的超级vip用户！" << std::endl;
    }
};


int main()
{
    PlatformFeature* platform = new PCPlatformFeature();
    Software* software = new SuperVIPVersionSoftware(platform);
    software->run();
    software->login();
    software->sendMessage();

    software = new NormalVersionSoftware(platform);
    software->run();
    software->login();
    software->sendMessage();

    system("pause");

    return 0;
}