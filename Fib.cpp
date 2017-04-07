#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#define MAXSIZE 255


using namespace std;



/*=========bool fibExist(float nTest, int *nFib)==========
nTest:所要计算的数列Fib[nTest]中的nTest
nFib:数列Fib[nTest]中的元素组成的数组的头指针
return: true，如果输入合法； false，如果输入不合法
假设输入的nTest为整数或小数，nFib为long long数组指针
=====================================================*/
bool fibExist(float nTest,long long*nFib)
{
    static map<int, long long>  myFibMap;
    if(int(nTest) != nTest || nTest < 1)//如果输入不是正整数 则返回错误标识
    {
        return false;
    }
    else
    {
        int nTestInt = int(nTest);//获得输入的整数版本
        map<int, long long>::iterator it = myFibMap.find(nTestInt);
        if(it == myFibMap.end())//如果在字典里没有找到nTest对应的fib(nTest)
        {
            long long sum, pre, pree, temp;
            bool firstTry = false;
            for(int i = myFibMap.size() + 1; i <= nTestInt; i++)//计算字典中没有的fib(nTest)
            {
                if(i == 1 || i == 2)//fib(1) = fib(2) = 1
                {
                    pre = 1;
                    pree = 0;
                }
                else//从字典中读取fib(i-1) fib(i-2)
                {
                    pree = myFibMap[i - 2];
                    pre = myFibMap[i - 1];
                }
                sum = pre + pree;
                myFibMap.insert(map<int, long long>::value_type(i, sum));//将得到的值插入字典中
            }
        }
        int j;
        for(j = 1; j <= nTestInt; j++)//将前nTest项斐波那契数列的值存入结果数组里
        {
            nFib[j - 1] = myFibMap[j];
        }
        return true;
    }
}

int main()
{
    int testNum;
    testNum = 8;//设定8个测试用例,<=255
    float testCase[testNum] = {-4, 0, 5, -6.43, 15, 65, 0.434, 90};
    long long testResult[MAXSIZE];//存放运算结果的数组
    for(int i = 0; i < testNum; i++)
    {
        if (fibExist(testCase[i],testResult))//若计算结果存在
        {
            cout << i + 1 << ".Fib(" << testCase[i] << "):";
            for (int j = 0; j < int(testCase[i]); j++)//则依次输出斐波那契数组每项值
            {
                cout << testResult[j] << " ";
            }
            cout << endl << endl;
        }
        else//若计算结果不存在，即测试用例输入不合法
        {
            cout << i + 1 << ".Fib(" << testCase[i] << "):ERROR!\n\n";//则给出错误提示
        }
    }
    return 0;
}
