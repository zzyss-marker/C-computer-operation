#include<iostream>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define OVERFLOW -2
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
typedef int ElemType;
typedef int Status;
using namespace std;

//˳���ṹ�嶨�� 
typedef  struct {
	ElemType* elem;    // �洢�ռ��ַ
	int length;        // ��ǰ����
	int listsize;      // ��ǰ����Ĵ洢���� 
} SqList;  // ˳���

// 1.����һ���������Ϊ LIST_INIT_SIZE��˳��� 
Status InitList(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
} // InitList

// 2.��˳����в�ѯ��һ�������ж�����������Ԫ�أ������ڣ��򷵻�����λ�򣬷��򷵻� 0
int LocateElem(SqList &L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	int j = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			j = i + 1;
			return j;
		}
	}
	return 0;
} // LocateElem 

// 3.��˳���L�ĵ� i ��λ�ò����µ�Ԫ��e 
Status ListInsert(SqList& L, int i, ElemType e) {
	L.length = L.length + 1;
	for (int j = L.length; j >= i; j--)
		L.elem[j] = L.elem[j-1];
	L.elem[i - 1] = e;
	return 1;
} // ListInsert                         

// 4.ɾ��˳���L�ĵ� i ��Ԫ�أ���e ������ֵ 
Status ListDelete(SqList& L, int i, ElemType& e) {
	e = L.elem[i - 1];
	for (int j = i - 1; j < L.length; j++)
		L.elem[j] = L.elem[j + 1];
	L.length = L.length - 1;
	return e;
} // ListDelete

//5����˳����е����ֵ���������ֵ�ƶ���˳����ĩβ������Ԫ�����Թ�ϵ���䡣
//������������
Status findmax(SqList& L)
{
	int max=0;
	int max_p = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] > max)
		{
			max = L.elem[i];
			max_p = i; //�б�����
		}
	}
	L.elem[L.length] = max;
	L.length++;
	ListDelete(L, max_p+1,L.elem[L.length]);//��ɾ�����ֵ��ԭ���е�����
	return 1;
}

//�����������Ա��Ԫ�أ��洢��˳��ṹ�� 
Status CreateList(SqList& L) {
	int lsize = 0;
	cout << "�������Ա�Ԫ�ظ���:" << endl;
	cin >> lsize;
	if (lsize > L.listsize)
		return ERROR;
	cout << "�������Ա�Ԫ��:" << endl;
	for (int i = 0; i < lsize; i++)
		cin >> L.elem[i];
	L.length = lsize;
	return TRUE;
}

//�������˳����Ԫ�� 
void Traverse(SqList L) {
	cout << "˳��������Ϊ:";
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << " ";
}

//�ȽϺ��� 
Status compare(ElemType a, ElemType b) {
	if (a == b)
		return TRUE;
	else
		return FALSE;
}

//����˳��� 
void DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}

int main(void) {
	int position;
	ElemType elem;
	SqList sl;
	int c = 0;
	while (c != 9) {
		cout << endl << "1. ������˳���";
		cout << endl << "2. �����Ա�Ԫ�ش���˳���";
		cout << endl << "3. ��˳����в���Ԫ��";
		cout << endl << "4. ��˳�����ɾ��Ԫ��";
		cout << endl << "5. ��˳����в���Ԫ��";
		cout << endl << "6. �������ֵ���ƶ���ĩβ";
		cout << endl << "7. ����˳���";
		cout << endl << "8. ����˳���";
		cout << endl << "9. �˳�";
		cout << endl << "ѡ����(1~9):";
		cin >> c;
		switch (c) {
		case 1: {
			if (InitList(sl))
				cout << "��˳������ɹ���";
			else
				cout << "��˳�����ʧ�ܡ�";
			break;
		}
		case 2: {
			if (CreateList(sl))
				Traverse(sl);
			else
				cout << "˳���洢ʧ��.";
			break;
		}
		case 3: {
			cout << "���������λ�ã�" << endl;
			cin >> position;
			cout << "������Ҫ���������:";
			cin >> elem;
			if (ListInsert(sl, position, elem)) {
				cout << "����ɹ���";
				Traverse(sl);
			}
			else {
				cout << "����ʧ�ܣ�";
				Traverse(sl);
			}
			break;
		}
		case 4: {
			cout << "����Ҫɾ�����ݵ�λ�ã�" << endl;
			cin >> position;
			if (ListDelete(sl, position, elem)) {
				cout << "ɾ���ɹ���";
				Traverse(sl);
			}
			else {
				cout << "ɾ��ʧ�ܣ�";
				Traverse(sl);
			}
			break;
		}
		case 5: {
			cout << "��������ҵ�����:" << endl;
			cin >> elem;
			position = LocateElem(sl, elem, compare);
			cout << "�������ҵ������ڵ�" << position << "��λ��" << endl;
			Traverse(sl);
			break;
		}
		case 6: {
			//��ѧ����ɶԡ��������ֵ���ƶ���ĩβ�������Ĳ���
			findmax(sl);
			Traverse(sl);
			// ��������޸�֮���˳���
			break;
		}
		case 7: {
			Traverse(sl);
			break;
		}
		case 8: {
			DestroyList(sl);
			cout << "�������" << endl;
			break;
		}
		case 9: {
			cout << "��������" << endl;
			exit(0);
			break;
		}
		}
	}
}
