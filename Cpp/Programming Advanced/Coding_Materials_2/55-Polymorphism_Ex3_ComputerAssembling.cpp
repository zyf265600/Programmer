#include <iostream>
using namespace std;

//抽象出每个零件的类
//抽象CPU类
class CPU
{
public:
    //虚计算函数
    virtual void calculate() = 0;
};

//抽象显卡类
class GPU
{
public:
    //虚显示函数
    virtual void display() = 0;
};

//抽象内存条类
class Memory
{
public:
    //虚储存函数
    virtual void storage() = 0;
};

//具体零件厂商
// Intel类
class IntelCPU : public CPU
{
    void calculate()
    {
        cout << "Intel CPU 开始处理数据！" << endl;
    }
};

class IntelGPU : public GPU
{
    void display()
    {
        cout << "Intel GPU 开始生成图像！" << endl;
    }
};
class IntelMemory : public Memory
{
    void storage()
    {
        cout << "Intel memory 开始储存数据！" << endl;
    }
};

// Lenovo类
class LenovoCPU : public CPU
{
    void calculate()
    {
        cout << "Lenovo CPU 开始处理数据！" << endl;
    }
};

class LenovoGPU : public GPU
{
    void display()
    {
        cout << "Lenovo GPU 开始生成图像！" << endl;
    }
};
class LenovoMemory : public Memory
{
    void storage()
    {
        cout << "Lenovo memory 开始储存数据！" << endl;
    }
};

//电脑类
class Computer
{
private:
    CPU *m_cpu;       // CPU的零件指针
    GPU *m_gpu;       //显卡零件指针
    Memory *m_memory; //内存条零件指针

public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }

    //提供工作的函数
    void work()
    {
        //让零件工作起来，调用接口
        m_cpu->calculate();

        m_gpu->display();

        m_memory->storage();
    }

    //提供析构函数 释放3个电脑零件
    ~Computer()
    {
        //释放CPU零件
        if (NULL != m_cpu)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        //释放显卡零件
        if (NULL != m_gpu)
        {
            delete m_gpu;
            m_gpu = NULL;
        }

        //释放内存条零件
        if (NULL != m_memory)
        {
            delete m_memory;
            m_memory = NULL;
        }
    }
};

void test01()
{
    //第一台电脑零件
    CPU *intelCpu = new IntelCPU;
    GPU *intelGpu = new IntelGPU;
    Memory *intelMemory = new IntelMemory;

    cout << "第一台电脑开始工作：" << endl;
    //创建第一台电脑
    Computer *computer1 = new Computer(intelCpu, intelGpu, intelMemory);
    computer1->work();
    delete computer1;

    cout << "-----------------------" << endl;
    cout << "第二台电脑开始工作：" << endl;
    //第二台电脑组装
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
    ;
    computer2->work();
    delete computer2;

    cout << "-----------------------" << endl;
    cout << "第三台电脑开始工作：" << endl;
    //第三台电脑组装
    Computer computer3(new LenovoCPU, new IntelGPU, new LenovoMemory);
    computer3.work();
}

int main()
{
    test01();
    return 0;
}