/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-27 11:06:31
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-27 11:47:00
 * @FilePath: \designMode\exercise\5.Bridge.cpp
 * @Description: Ϊ�˷��㣬û�з��ļ���
 * ���ȼ���һ��������ģʽ�ģ�2��������ά�ȵı仯������2��ά�Ȱɣ�
 * ���һ������������������ܶ�ӿڣ�����������¼��������Ϣ���Լ�
 * ��ʾ�ؼ����������ֵȵȡ����Բ���ͬƽ̨����ʾ�ؼ��Ͳ������ֵķ�ʽ
 * �ǲ�һ���ģ���pc�Ͱ�׿��ʾ�Ͳ��Ŵ��벻ͬ�������ڲ�ͬ����汾��
 * ������¼������ϢҲ�ǲ�һ���ģ�����ͨ��ɶҲû�У���Ա�����ʾ��ͬ
 * ͼ�������Ų�ͬ��Ч�ȵȣ�������ά�ȵı仯��
 * 
 * Copyright (c) 2023 by ë����Ұ��, All Rights Reserved. 
 */
// �������麯�������� = 0�������к����壡����


#include <iostream>

class PlatformFeature;

class Software
{
public:
    PlatformFeature* m_platformFeature;
public:
    Software(PlatformFeature* platformFeature) : m_platformFeature(platformFeature) {}
    virtual ~Software() {} // �������麯�������� = 0�������к����壡����

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

//����ƽ̨����ʵ��
class PCPlatformFeature : public PlatformFeature
{
public:
    void showPicture() override
    {
        std::cout << "pc�˿�ʼ��ʾͼƬ" << std::endl;
    }
    void playRadio() override
    {
        std::cout << "pc�˿�ʼ������Ч" << std::endl;
    }
};

class AndroidPlatformFeature : public PlatformFeature
{
public:
    void showPicture() override
    {
        std::cout << "android�˿�ʼ��ʾͼƬ" << std::endl;
    }
    void playRadio() override
    {
        std::cout << "android�˿�ʼ������Ч" << std::endl;
    }
};

class IOSPlatformFeature : public PlatformFeature
{
public:
    void showPicture() override
    {
        std::cout << "ios�˿�ʼ��ʾͼƬ" << std::endl;
    }
    void playRadio() override
    {
        std::cout << "ios�˿�ʼ������Ч" << std::endl;
    }
};

//���ְ汾����ʵ��
class NormalVersionSoftware : public Software
{
public:
    NormalVersionSoftware(PlatformFeature* platformFeature) : Software(platformFeature) {}
    ~NormalVersionSoftware() override { std::cout; }

    void run() override
    {
        std::cout << "���������" << std::endl;
    }
    void login() override
    {
        std::cout << "�����¼��" << std::endl;
    }
    void sendMessage() override
    {
        std::cout << "�������ߣ�" << std::endl;
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
        std::cout << "���������" << std::endl;
    }
    void login() override
    {
        m_platformFeature->showPicture();
        std::cout << "�����¼��" << std::endl;
    }
    void sendMessage() override
    {
        m_platformFeature->showPicture();
        std::cout << "�������ߣ�" << std::endl;
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
        std::cout << "���������" << std::endl;
    }
    void login() override
    {
        m_platformFeature->showPicture();
        m_platformFeature->playRadio();
        std::cout << "�����¼��" << std::endl;
    }
    void sendMessage() override
    {
        m_platformFeature->showPicture();
        m_platformFeature->playRadio();
        std::cout << "�������������𾴵ĳ���vip�û���" << std::endl;
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