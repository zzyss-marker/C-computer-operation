#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;

// ��㶨�� 
typedef struct LNode {
    ElemType data;  // ������
    struct LNode* next;  // ָ����
} Lnode, * LinkList;

//1. ��β�巨���쵥����
void CreateListTail(LinkList& L, int n) {
    L = new Lnode; // ����ͷ���
    L->next = nullptr;
    Lnode* tail = L;
    for (int i = 0; i < n; ++i) {
        Lnode* newNode = new Lnode;
        cin >> newNode->data;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
}

//2. ��ͷ�巨���쵥����
void CreateListHead(LinkList& L, int n) {
    L = new Lnode; // ����ͷ���
    L->next = nullptr; // ��ʼ��ͷ����ָ��
    for (int i = 0; i < n; ++i) {
        Lnode* newNode = new Lnode;
        cin >> newNode->data;
        newNode->next = L->next; // ���뵽ͷ��
        L->next = newNode; // ����ͷ����ָ��
    }
}

//3. ���ص������е�i������ֵ 
Status GetElem(LinkList L, int i, ElemType& e) {
    int index = 1;
    Lnode* current = L->next; // ����ͷ���
    while (current && index < i) {
        current = current->next;
        index++;
    }
    if (!current || index > i) return 0; // ����0��ʾʧ��
    e = current->data;
    return 1; // �ɹ�
}

//4. �ڵ�����iλ�ò���Ԫ��e 
Status ListInsert(LinkList& L, int i, ElemType e) {
    if (i < 1) return 0;
    Lnode* newNode = new Lnode;
    newNode->data = e;
    newNode->next = nullptr;
    Lnode* current = L;
    int index = 0;
    while (current && index < i - 1) {
        current = current->next;
        index++;
    }
    if (!current) return 0; // ����λ����Ч
    newNode->next = current->next;
    current->next = newNode;
    return 1; // �ɹ�
}

//5. ɾ����������λ��iλ�õĽ��
Status ListDelete(LinkList& L, int i, ElemType& e) {
    if (!L->next) return 0; // ����Ϊ��
    Lnode* current = L;
    int index = 0;
    while (current->next && index < i - 1) {
        current = current->next;
        index++;
    }
    if (!current->next || index > i - 1) return 0; // δ�ҵ���i��Ԫ��
    Lnode* toDelete = current->next;
    e = toDelete->data;
    current->next = toDelete->next;
    delete toDelete;
    cout << "��ɾ����" << i << "��Ԫ��" << endl;
    return 1; // �ɹ�
}

//6. ��յ����� 
void ClearList(LinkList& L) {
    Lnode* current = L;
    while (current) {
        Lnode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    L = nullptr;
}

//7. ���������� 
void Traverse(LinkList L) {
    Lnode* current = L->next; // ����ͷ���
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//8. ���ٵ����� 
void DestroyList(LinkList& L) {
    ClearList(L);
}

//9. ɾ����������ֵΪe�Ľ��
void DeleteElem(LinkList& L, ElemType e) {
    if (!L->next) {
        cout << "����Ϊ��" << endl;
        return;
    }
    Lnode* current = L;
    while (current->next) {
        if (current->next->data == e) {
            Lnode* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
            cout << "��ɾ��" << e << "Ԫ��" << endl;
            return;
        }
        current = current->next;
    }
    cout << "δ�ҵ�" << e << "Ԫ��" << endl;
}

int main(void) {
    LinkList L;
    L = new Lnode; // ͷ���
    L->next = nullptr;
    int c = 0;
    while (c != 9) {
        cout << endl << "1. ͷ�巨����������";
        cout << endl << "2. β�巨����������";
        cout << endl << "3. �ڵ������в��ҵ�i��Ԫ��";
        cout << endl << "4. �ڵ������е�i��λ�ò���Ԫ��";
        cout << endl << "5. �ڵ�������ɾ����i��Ԫ��";
        cout << endl << "6. �ڵ�������ɾ��eԪ��";
        cout << endl << "7. ����������";
        cout << endl << "8. ���ٵ�����";
        cout << endl << "9. �˳�";
        cout << endl << "ѡ����(1~9):";
        cin >> c;
        switch (c) {
        case 1: {
            int n;
            cout << "����Ԫ�ظ���: ";
            cin >> n;
            CreateListHead(L, n);
            Traverse(L);
            break;
        }
        case 2: {
            int n;
            cout << "����Ԫ�ظ���: ";
            cin >> n;
            CreateListTail(L, n);
            Traverse(L);
            break;
        }
        case 3: {
            int i;
            ElemType e;
            cout << "����λ��i: ";
            cin >> i;
            if (GetElem(L, i, e))
                cout << "��" << i << "��Ԫ����: " << e << endl;
            else
                cout << "δ�ҵ���" << i << "��Ԫ��" << endl;
            break;
        }
        case 4: {
            int i;
            ElemType e;
            cout << "����λ��i��Ԫ��e: ";
            cin >> i >> e;
            if (ListInsert(L, i, e))
            {
                cout << "����ɹ�" << endl;
                Traverse(L);
            }
            else
                cout << "����ʧ��" << endl;
            break;
        }
        case 5: {
            int i;
            ElemType e;
            cout << "����λ��i: ";
            cin >> i;
            if (ListDelete(L, i, e))
            {
                cout << "��ɾ����" << i << "��Ԫ�أ�ֵΪ" << e << endl;
                Traverse(L);
            }
            else
                cout << "ɾ��ʧ��" << endl;
            break;
        }
        case 6: {
            ElemType e;
            cout << "����ֵe: ";
            cin >> e;
            DeleteElem(L, e);
            Traverse(L);
            break;
        }
        case 7: {
            Traverse(L);
            break;
        }
        case 8: {
            DestroyList(L);
            cout << "���ٳɹ���";
            break;
        }
        case 9: {
            cout << "��������" << endl;
            exit(0);
            break;
        }
        }
    }
    return 0;
}

