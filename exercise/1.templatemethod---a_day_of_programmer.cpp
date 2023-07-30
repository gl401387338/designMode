/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-07-30 11:19:50
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-07-30 11:55:13
 * @FilePath: \designMode\exercise\1.templatemethod---a_day_of_programmer.cpp
 * @Description: 第一个设计模式代码案例。为了代码便于管理，所以我将定义和实现写一块了，特此声明！，还是懒。。
 * 内容跟笔记一样实现一个打工人的一天，这样一个抽象，具体如下：
 *   模板方法模式：整体结构稳定。但是子步骤变化，或者晚期实现需求。（例如==打工人的一天==：
 * 一天中的整体结构，或者说流程稳定，比如早上起床-》吃饭-》去公司-》卷一上午-》吃午饭-》
 * 卷一下午-》吃晚饭-》卷一晚上-》吃夜宵-》回家-》睡觉。==其中==一天的结构是固定的，但是
 * 吃早中晚夜等饭的子步骤是变化的，比如我今天早上吃包子，中午吃面等等。所以如果要针对这种
 * 需求，将其抽象出来，实现代码的话，可以采用Template Method模式，==具体==：首先定义一个
 * 《打工人类》，其中有一个《一天生活》的函数，在该函数中，会调用一套稳定的子步骤，如《起床》
 * 《吃早餐》《上班》等等，这时其中需要变化的子步骤函数可以定义为虚函数，再定义一个子类《
 * 今天的打工人》重写这些需要变化的虚函数，从而实现每天吃不同饭的这种模式。）
 * 
 * Copyright (c) 2023 by 毛利的野望, All Rights Reserved. 
 */
#include <iostream>
#include <memory>
class Programmer
{
public:
    Programmer() { std::cout << "打工人的一天开始啦！-》" << std::endl; } 
    virtual ~Programmer() { std::cout << "打工人的一天结束啦！" << std::endl; }

    void runToday()
    {
        wakeUp();
        eatBreakfast();
        doMorningWork();
        eatLunch();
        doAfternoonWork();
        eatDinner();
        backHouse();
        sleep();
    }
    void wakeUp() { std::cout << "起床-》" << std::endl; }
    void doMorningWork() { std::cout << "早上打工ing-》" << std::endl; }
    void doAfternoonWork() { std::cout << "下午打工ing-》" << std::endl; }
    void backHouse() { std::cout << "回家啦-》" << std::endl; }
    void sleep() { std::cout << "睡觉ing-》" << std::endl; }
    
protected:
    virtual void eatBreakfast() {}
    virtual void eatLunch() {}
    virtual void eatDinner() {}
};

class TodayProgrammer : public Programmer
{
public:
    TodayProgrammer() { std::cout << "今天是xxx号！-》" << std::endl; }
    ~TodayProgrammer(){ std::cout << "今天是xxx号！-》" << std::endl; }

protected:
    void eatBreakfast() override { std::cout << "吃包子-》" << std::endl; }
    void eatLunch() override { std::cout << "吃牛肉面-》" << std::endl; }
    void eatDinner() override { std::cout << "吃羊腿-》" << std::endl; }
};

int main()
{
    Programmer* worker = new TodayProgrammer();
    worker->runToday();
    delete worker;

    std::unique_ptr<Programmer> worker1 = std::make_unique<TodayProgrammer>();
    worker1->runToday();
    
    system("pause");
    return 0;
}

