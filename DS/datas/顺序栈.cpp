#include<iostream>
using namespace std;
typedef int SElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

// ˳��ջ�ṹ�嶨�� 
typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} SqStack;

// ��ʼ��ջ 
Status InitStack(SqStack& S) {
    S.base = new SElemType[STACK_INIT_SIZE];
    if (!S.base) return ERROR;  // ����ʧ��
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

// ��Ԫ��e��ջ 
Status Push(SqStack& S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {  // ջ������չ�ռ�
        SElemType* newbase = new SElemType[S.stacksize + STACKINCREMENT];
        if (!newbase) return ERROR;  // ����ʧ��
        for (int i = 0; i < S.stacksize; i++) {
            newbase[i] = S.base[i];
        }
        delete[] S.base;
        S.base = newbase;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

// ��ջ����e���س�ջԪ�� 
Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base) return ERROR;  // ջ��
    e = *--S.top;
    return OK;
}

// ����ջ��Ԫ�� 
Status GetTop(SqStack S, SElemType& e) {
    if (S.top == S.base) return ERROR;  // ջ��
    e = *(S.top - 1);
    return OK;
}

// ���ջ����Ϊ��ջ 
void Clear(SqStack& S) {
    S.top = S.base;
}

// ����ջԪ�أ���ջ�׵�ջ���� 
void Traverse(SqStack S) {
    SElemType* p = S.base;
    while (p != S.top) {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

// ����ת������, ��ʮ������decת��Ϊn������, �����ת������ 
void Convert(int dec, int n) {
    SqStack S;
    InitStack(S);
    while (dec != 0) {
        Push(S, dec % n);
        dec /= n;
    }
    SElemType e;
    while (Pop(S, e) == OK) {
        if (e < 10)
            cout << e;
        else
            cout << char(e - 10 + 'A');
    }
    cout << endl;
}

// ������ 
int main(void) {
    SqStack st;
    InitStack(st);
    int c = 0;
    while (c != 7) {
        cout << endl << "1. ��ջ";
        cout << endl << "2. ��ջ";
        cout << endl << "3. ��ջ��";
        cout << endl << "4. ����ջ";
        cout << endl << "5. ���˳��ջ";
        cout << endl << "6. ����ת��";
        cout << endl << "7. �˳�";
        cout << endl << "ѡ����(1~7):";
        cin >> c;
        SElemType e;
        int dec, n;
        switch (c) {
        case 1:
            cout << "������ջԪ��:";
            cin >> e;
            if (Push(st, e) == OK)
                cout << "Ԫ�� " << e << " ��ջ�ɹ���" << endl;
            else
                cout << "��ջʧ�ܣ�" << endl;
            break;
        case 2:
            if (Pop(st, e) == OK)
                cout << "��ջԪ��: " << e << endl;
            else
                cout << "ջΪ�գ��޷���ջ��" << endl;
            break;
        case 3:
            if (GetTop(st, e) == OK)
                cout << "ջ��Ԫ��: " << e << endl;
            else
                cout << "ջΪ�գ�" << endl;
            break;
        case 4:
            cout << "ջ��Ԫ��Ϊ: ";
            Traverse(st);
            break;
        case 5:
            Clear(st);
            cout << "ջ����գ�" << endl;
            break;
        case 6:
            cout << "����ʮ��������Ŀ����� (����: 100 2): ";
            cin >> dec >> n;
            cout << dec << " �� " << n << " ���Ʊ�ʾΪ: ";
            Convert(dec, n);
            break;
        case 7:
            cout << "�����˳���" << endl;
            break;
        default:
            cout << "��Ч��ѡ�����������룡" << endl;
        }
    }
    delete[] st.base;
    return 0;
}
