#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

class Student {
private:
    long num;             // ѧ��
    char name[10];        // ����
    float score;          // ����
public:
    Student(long n, const char* nm, float s) {
        num = n;
        strncpy(name, nm, sizeof(name));   // ʹ�� strncpy �����ַ������������
        score = s;
    }

    long getNum() const {
        return num;
    }

    const char* getName() const {
        return name;
    }

    float getScore() const {
        return score;
    }
};

class LinearList {
private:
    Student* data[MAX_SIZE];    // ����ѧ������ָ�������
    int length;                 // ��ǰ���Ա���
public:
    LinearList() {
        length = 0;
    }

    void insert(Student* student) {
        if (length >= MAX_SIZE) {             // ������Ա��������޷���������
            cout << "���Ա��������޷��������ݣ�" << endl;
            return;
        }

        int i;
        for (i = length - 1; i >= 0; i--) {    // ���ݷ����Ӹߵ����ҵ�����λ��
            if (student->getScore() < data[i]->getScore()) {
                data[i + 1] = data[i];         // ����ƶ�Ԫ��
            }
            else {
                break;
            }
        }
        data[i + 1] = student;                  // ����Ԫ��
        length++;
    }

    void remove(long num) {
        int i;
        for (i = 0; i < length; i++) {          // ����Ҫɾ����Ԫ��λ��
            if (data[i]->getNum() == num) {
                break;
            }
        }
        if (i == length) {                      // ���δ�ҵ���Ӧѧ�ŵ�ѧ����Ϣ
            cout << "δ�ҵ�ѧ��Ϊ " << num << " ��ѧ����Ϣ��" << endl;
            return;
        }
        for (; i < length - 1; i++) {           // ��ǰ�ƶ�Ԫ��
            data[i] = data[i + 1];
        }
        length--;
    }

    void display() {
        cout << "ѧ���ɼ���" << endl;
        for (int i = 0; i < length; i++) {      // ��ʾѧ����Ϣ
            cout << "ѧ�ţ�" << data[i]->getNum()
                << " ������" << data[i]->getName()
                << " ������" << data[i]->getScore() << endl;
        }
    }

    static LinearList mergeLists(const LinearList& list1, const LinearList& list2) {
        LinearList mergedList;
        int i = 0, j = 0;
        while (i < list1.length && j < list2.length) {    // �ϲ��������Ա�
            if (list1.data[i]->getScore() < list2.data[j]->getScore()) {
                mergedList.insert(list1.data[i]);         // ����С��Ԫ�ز��뵽�ϲ�������Ա�
                i++;
            }
            else {
                mergedList.insert(list2.data[j]);
                j++;
            }
        }
        while (i < list1.length) {                        // ��ʣ���Ԫ�ز��뵽�ϲ�������Ա�
            mergedList.insert(list1.data[i]);
            i++;
        }
        while (j < list2.length) {
            mergedList.insert(list2.data[j]);
            j++;
        }
        return mergedList;
    }
};

int main() {
    LinearList list;

    while (true) {
        cout << "��ѡ�������" << endl;
        cout << "1. ����ѧ����Ϣ" << endl;
        cout << "2. ɾ��ѧ����Ϣ" << endl;
        cout << "3. ��ʾѧ���ɼ���" << endl;
        cout << "4. �ϲ�������" << endl;
        cout << "0. �˳�����" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            long num;
            char name[10];
            float score;
            cout << "������ѧ��ѧ�ţ�";
            cin >> num;
            cout << "������ѧ��������";
            cin >> name;
            cout << "������ѧ���ɼ���";
            cin >> score;

            Student* student = new Student(num, name, score);   // ����ѧ������
            list.insert(student);                               // ����ѧ����Ϣ�����Ա�
            cout << "ѧ����Ϣ�Ѳ���ɹ���" << endl;
        }
        else if (choice == 2) {
            long num;
            cout << "������Ҫɾ����ѧ��ѧ�ţ�";
            cin >> num;
            list.remove(num);                                   // ɾ��ѧ����Ϣ
        }
        else if (choice == 3) {
            list.display();                                     // ��ʾѧ���ɼ���
        }
        else if (choice == 4) {
            LinearList list2;
            // ��ڶ������Ա��в���ѧ����Ϣ
            long num;
            char name[10];
            float score;
            cout << "������ѧ��ѧ�ţ�";
            cin >> num;
            cout << "������ѧ��������";
            cin >> name;
            cout << "������ѧ���ɼ���";
            cin >> score;

            Student* student = new Student(num, name, score);   // ����ѧ������
            list2.insert(student);                              // ����ѧ����Ϣ���ڶ������Ա�
            cout << "ѧ����Ϣ�Ѳ���ɹ���" << endl;

            LinearList mergedList = LinearList::mergeLists(list, list2);   // �ϲ��������Ա�
            cout << "�ϲ����ѧ���ɼ���" << endl;
            mergedList.display();                              // ��ʾ�ϲ����ѧ���ɼ���
        }
        else if (choice == 0) {
            break;                                              // �˳�����
        }
        else {
            cout << "��Ч��ѡ�����������룡" << endl;
        }

        cout << endl;
    }

    return 0;
}