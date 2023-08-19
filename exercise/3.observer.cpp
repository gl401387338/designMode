/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-19 16:18:31
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-19 16:46:40
 * @FilePath: \designMode\exercise\3.observer.cpp
 * @Description: 观察者模式练习：进度条显示器（进度条观察者）
 * 没有实现的具体代码，只有一个框架。
 * Copyright (c) 2023 by 毛利的野望, All Rights Reserved. 
 */
// 观察者
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

// class xxxProgress....(自己扩展观察者类)

//目标（调用观察者的主体）
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