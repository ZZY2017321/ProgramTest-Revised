#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#define MAXSIZE 255


using namespace std;



/*=========bool fibExist(float nTest, int *nFib)==========
nTest:��Ҫ���������Fib[nTest]�е�nTest
nFib:����Fib[nTest]�е�Ԫ����ɵ������ͷָ��
return: true���������Ϸ��� false��������벻�Ϸ�
���������nTestΪ������С����nFibΪlong long����ָ��
=====================================================*/
bool fibExist(float nTest,long long*nFib)
{
    static map<int, long long>  myFibMap;
    if(int(nTest) != nTest || nTest < 1)//������벻�������� �򷵻ش����ʶ
    {
        return false;
    }
    else
    {
        int nTestInt = int(nTest);//�������������汾
        map<int, long long>::iterator it = myFibMap.find(nTestInt);
        if(it == myFibMap.end())//������ֵ���û���ҵ�nTest��Ӧ��fib(nTest)
        {
            long long sum, pre, pree, temp;
            bool firstTry = false;
            for(int i = myFibMap.size() + 1; i <= nTestInt; i++)//�����ֵ���û�е�fib(nTest)
            {
                if(i == 1 || i == 2)//fib(1) = fib(2) = 1
                {
                    pre = 1;
                    pree = 0;
                }
                else//���ֵ��ж�ȡfib(i-1) fib(i-2)
                {
                    pree = myFibMap[i - 2];
                    pre = myFibMap[i - 1];
                }
                sum = pre + pree;
                myFibMap.insert(map<int, long long>::value_type(i, sum));//���õ���ֵ�����ֵ���
            }
        }
        int j;
        for(j = 1; j <= nTestInt; j++)//��ǰnTest��쳲��������е�ֵ������������
        {
            nFib[j - 1] = myFibMap[j];
        }
        return true;
    }
}

int main()
{
    int testNum;
    testNum = 8;//�趨8����������,<=255
    float testCase[testNum] = {-4, 0, 5, -6.43, 15, 65, 0.434, 90};
    long long testResult[MAXSIZE];//���������������
    for(int i = 0; i < testNum; i++)
    {
        if (fibExist(testCase[i],testResult))//������������
        {
            cout << i + 1 << ".Fib(" << testCase[i] << "):";
            for (int j = 0; j < int(testCase[i]); j++)//���������쳲���������ÿ��ֵ
            {
                cout << testResult[j] << " ";
            }
            cout << endl << endl;
        }
        else//�������������ڣ��������������벻�Ϸ�
        {
            cout << i + 1 << ".Fib(" << testCase[i] << "):ERROR!\n\n";//�����������ʾ
        }
    }
    return 0;
}
