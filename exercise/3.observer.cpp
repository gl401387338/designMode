/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-19 16:18:31
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-19 16:46:40
 * @FilePath: \designMode\exercise\3.observer.cpp
 * @Description: �۲���ģʽ��ϰ����������ʾ�����������۲��ߣ�
 * û��ʵ�ֵľ�����룬ֻ��һ����ܡ�
 * Copyright (c) 2023 by ë����Ұ��, All Rights Reserved. 
 */
// �۲���
class Progress
{
public:
    virtual ~Progress();
    virtual void doProgress(float progress);
};

class PointProgress : public Progress
{
public:
    ~PointProgress() override;
    void doProgress(float progress) override;
};

class BarProgress : public Progress
{
public:
    ~BarProgress() override;
    void doProgress(float progress) override;
};

class digitProgress : public Progress
{
public:
    ~digitProgress() override;
    void doProgress(float progress) override;
};

// class xxxProgress....(�Լ���չ�۲�����)

//Ŀ�꣨���ù۲��ߵ����壩
class Subject
{
    virtual ~Subject();
    virtual void attachProgress(Progress* progress);
    virtual void detachProgress(Progress* progress);
    virtual void onProgress(float value);
};


int main()
{


    return 0;
}