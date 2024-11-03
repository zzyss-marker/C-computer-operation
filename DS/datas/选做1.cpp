#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;

// ��㶨�� 
typedef struct LNode {
    ElemType data;  // ������
    struct LNode* next;  // ָ����
} Lnode, * LinkList;

// ����ֵ��С����Ԫ�أ�������������
void InsertInOrder(LinkList& L, ElemType e) {
    Lnode* newNode = new Lnode;
    newNode->data = e;
    newNode->next = nullptr;

    // �������Ϊ�ջ��߲����Ԫ�ر�ͷ���С
    if (!L || L->next == nullptr || L->next->data >= e) {
        newNode->next = L ? L->next : nullptr; // ���LΪ�գ�ֱ�Ӳ���
        if (L) {
            L->next = newNode;
        }
        else {
            L = new Lnode; // ����ͷ���
            L->next = newNode;
        }
        return;
    }

    // ���Ҳ���λ��
    Lnode* current = L->next;
    Lnode* prev = L;

    while (current && current->data < e) {
        prev = current;
        current = current->next;
    }

    newNode->next = current;
    prev->next = newNode;
}

// ���������� 
void Traverse(LinkList L) {
    Lnode* current = L->next; // ����ͷ���
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(void) {
    LinkList L = nullptr; // ��ʼ������
    int n;
    cout << "����Ҫ�����Ԫ�ظ���: ";
    cin >> n;

    cout << "����Ԫ��: ";
    for (int i = 0; i < n; ++i) {
        ElemType e;
        cin >> e;
        InsertInOrder(L, e); // ��˳�����Ԫ��
    }

    cout << "���������е�Ԫ��Ϊ: ";
    Traverse(L); // �����������

    return 0;
}
