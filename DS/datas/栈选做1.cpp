#include <iostream>
#include <string>

#define MAX_SIZE 100 // ջ���������

using namespace std;

// ˳��ջ�Ķ���
class Stack {
private:
    char data[MAX_SIZE];
    int top;

public:
    // ��ʼ��ջ
    Stack() {
        top = -1;
    }

    // ���ջ�Ƿ�Ϊ��
    bool isEmpty() {
        return top == -1;
    }

    // ���ջ�Ƿ�����
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // ��ջ����
    bool push(char c) {
        if (!isFull()) {
            data[++top] = c;
            return true;
        }
        return false;
    }

    // ��ջ����
    bool pop(char& c) {
        if (!isEmpty()) {
            c = data[top--];
            return true;
        }
        return false;
    }

    // ��ȡջ��Ԫ��
    char getTop() {
        if (!isEmpty()) {
            return data[top];
        }
        return '\0'; // ���ؿ��ַ���ʾջΪ��
    }
};

// �ж����������Ƿ�ƥ��
bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') || (left == '[' && right == ']');
}

// �����ʽ�е�����ƥ��
bool checkBrackets(const string& expression) {
    Stack stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[') {
            // ���������ţ���ջ
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']') {
            // ���������ţ����ջ�Ƿ�Ϊ��
            if (stack.isEmpty()) {
                return false; // �����Ŷ���
            }
            char topChar;
            stack.pop(topChar);
            if (!isMatchingPair(topChar, ch)) {
                return false; // ��ƥ��
            }
        }
    }
    // ���ջ�Ƿ�Ϊ��
    return stack.isEmpty(); // ջ�ձ�ʾƥ����ȷ��ջ�ǿձ�ʾ�����Ŷ���
}

int main() {
    string expression;
    cout << "����������������ŵı��ʽ��";
    getline(cin, expression);

    if (checkBrackets(expression)) {
        cout << "���ʽ�е�����ƥ����ȷ��" << endl;
    }
    else {
        cout << "���ʽ�е�����ƥ�䲻��ȷ��" << endl;
    }

    return 0;
}
