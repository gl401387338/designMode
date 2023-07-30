/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-07-30 11:19:50
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-07-30 11:55:13
 * @FilePath: \designMode\exercise\1.templatemethod---a_day_of_programmer.cpp
 * @Description: ��һ�����ģʽ���밸����Ϊ�˴�����ڹ��������ҽ������ʵ��дһ���ˣ��ش�������������������
 * ���ݸ��ʼ�һ��ʵ��һ�����˵�һ�죬����һ�����󣬾������£�
 *   ģ�巽��ģʽ������ṹ�ȶ��������Ӳ���仯����������ʵ�����󡣣�����==���˵�һ��==��
 * һ���е�����ṹ������˵�����ȶ�������������-���Է�-��ȥ��˾-����һ����-�����緹-��
 * ��һ����-������-����һ����-����ҹ��-���ؼ�-��˯����==����==һ��Ľṹ�ǹ̶��ģ�����
 * ��������ҹ�ȷ����Ӳ����Ǳ仯�ģ������ҽ������ϳ԰��ӣ��������ȵȡ��������Ҫ�������
 * ���󣬽�����������ʵ�ִ���Ļ������Բ���Template Methodģʽ��==����==�����ȶ���һ��
 * �������ࡷ��������һ����һ������ĺ������ڸú����У������һ���ȶ����Ӳ��裬�硶�𴲡�
 * ������͡����ϰࡷ�ȵȣ���ʱ������Ҫ�仯���Ӳ��躯�����Զ���Ϊ�麯�����ٶ���һ�����ࡶ
 * ����Ĵ��ˡ���д��Щ��Ҫ�仯���麯�����Ӷ�ʵ��ÿ��Բ�ͬ��������ģʽ����
 * 
 * Copyright (c) 2023 by ë����Ұ��, All Rights Reserved. 
 */
#include <iostream>
#include <memory>
class Programmer
{
public:
    Programmer() { std::cout << "���˵�һ�쿪ʼ����-��" << std::endl; } 
    virtual ~Programmer() { std::cout << "���˵�һ���������" << std::endl; }

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
    void wakeUp() { std::cout << "��-��" << std::endl; }
    void doMorningWork() { std::cout << "���ϴ�ing-��" << std::endl; }
    void doAfternoonWork() { std::cout << "�����ing-��" << std::endl; }
    void backHouse() { std::cout << "�ؼ���-��" << std::endl; }
    void sleep() { std::cout << "˯��ing-��" << std::endl; }
    
protected:
    virtual void eatBreakfast() {}
    virtual void eatLunch() {}
    virtual void eatDinner() {}
};

class TodayProgrammer : public Programmer
{
public:
    TodayProgrammer() { std::cout << "������xxx�ţ�-��" << std::endl; }
    ~TodayProgrammer(){ std::cout << "������xxx�ţ�-��" << std::endl; }

protected:
    void eatBreakfast() override { std::cout << "�԰���-��" << std::endl; }
    void eatLunch() override { std::cout << "��ţ����-��" << std::endl; }
    void eatDinner() override { std::cout << "������-��" << std::endl; }
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

