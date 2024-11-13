#include<iostream>
#include <stdlib.h>
using namespace std;
typedef int SElemType;
typedef int Status;

#define OK 1
#define ERROR 0

// ��ջ�ṹ�嶨�� 
typedef struct SNode {
    SElemType data;
    SNode* next;
} SNode, * LinkStack;

// ��Ԫ��e��ջ 
Status Push(LinkStack& S, SElemType e) {
    SNode* newNode = new SNode;
    if (!newNode) return ERROR;  // ����ʧ��
    newNode->data = e;
    newNode->next = S;
    S = newNode;
    return OK;
}

// ��ջ����e���س�ջԪ�� 
Status Pop(LinkStack& S, SElemType& e) {
    if (S == NULL) return ERROR;  // ջ��
    SNode* p = S;
    e = p->data;
    S = S->next;
    delete p;
    return OK;
}

// ����ջ��Ԫ�� 
Status GetTop(LinkStack S, SElemType& e) {
    if (S == NULL) return ERROR;  // ջ��
    e = S->data;
    return OK;
}

// ���ջ����Ϊ��ջ 
void Clear(LinkStack& S) {
    SNode* p;
    while (S) {
        p = S;
        S = S->next;
        delete p;
    }
}

// ����ջԪ�أ���ջ����ջ�ף� 
void Traverse(LinkStack S) {
    SNode* p = S;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// �ж������ַ����Ƿ�Ϊ����
void HuiWen() {
    string str;
    cout << "�����ַ���: ";
    cin >> str;

    LinkStack S = NULL;
    for (char ch : str) {  // ���ַ���ѹ��ջ��
        Push(S, ch);
    }

    bool isPalindrome = true;
    for (char ch : str) {  // ��ջ������
        SElemType top;
        Pop(S, top);
        if (ch != top) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "\"" << str << "\" �ǻ���" << endl;
    else
        cout << "\"" << str << "\" ���ǻ���" << endl;
}

// ������
int main(void) {
    LinkStack st = NULL;
    int c = 0;
    while (c != 7) {
        cout << endl << "1. ��ջ";
        cout << endl << "2. ��ջ";
        cout << endl << "3. ��ջ��";
        cout << endl << "4. ����ջ";
        cout << endl << "5. ���ջ";
        cout << endl << "6. �����ж�";
        cout << endl << "7. �˳�";
        cout << endl << "ѡ����(1~7):";
        cin >> c;

        SElemType e;
        switch (c) {
        case 1:
            cout << "������ջԪ��: ";
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
            HuiWen();
            break;
        case 7:
            cout << "�����˳���" << endl;
            Clear(st);  // �˳�ǰ���ջ
            break;
        default:
            cout << "��Ч��ѡ�����������룡" << endl;
        }
    }
    return 0;
}
