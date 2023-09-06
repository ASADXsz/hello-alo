#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

class Student {
private:
    long num;             // 学号
    char name[10];        // 姓名
    float score;          // 分数
public:
    Student(long n, const char* nm, float s) {
        num = n;
        strncpy(name, nm, sizeof(name));   // 使用 strncpy 复制字符串，避免溢出
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
    Student* data[MAX_SIZE];    // 保存学生对象指针的数组
    int length;                 // 当前线性表长度
public:
    LinearList() {
        length = 0;
    }

    void insert(Student* student) {
        if (length >= MAX_SIZE) {             // 如果线性表已满，无法插入数据
            cout << "线性表已满，无法插入数据！" << endl;
            return;
        }

        int i;
        for (i = length - 1; i >= 0; i--) {    // 根据分数从高到低找到插入位置
            if (student->getScore() < data[i]->getScore()) {
                data[i + 1] = data[i];         // 向后移动元素
            }
            else {
                break;
            }
        }
        data[i + 1] = student;                  // 插入元素
        length++;
    }

    void remove(long num) {
        int i;
        for (i = 0; i < length; i++) {          // 查找要删除的元素位置
            if (data[i]->getNum() == num) {
                break;
            }
        }
        if (i == length) {                      // 如果未找到对应学号的学生信息
            cout << "未找到学号为 " << num << " 的学生信息！" << endl;
            return;
        }
        for (; i < length - 1; i++) {           // 向前移动元素
            data[i] = data[i + 1];
        }
        length--;
    }

    void display() {
        cout << "学生成绩表：" << endl;
        for (int i = 0; i < length; i++) {      // 显示学生信息
            cout << "学号：" << data[i]->getNum()
                << " 姓名：" << data[i]->getName()
                << " 分数：" << data[i]->getScore() << endl;
        }
    }

    static LinearList mergeLists(const LinearList& list1, const LinearList& list2) {
        LinearList mergedList;
        int i = 0, j = 0;
        while (i < list1.length && j < list2.length) {    // 合并两个线性表
            if (list1.data[i]->getScore() < list2.data[j]->getScore()) {
                mergedList.insert(list1.data[i]);         // 将较小的元素插入到合并后的线性表
                i++;
            }
            else {
                mergedList.insert(list2.data[j]);
                j++;
            }
        }
        while (i < list1.length) {                        // 将剩余的元素插入到合并后的线性表
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
        cout << "请选择操作：" << endl;
        cout << "1. 插入学生信息" << endl;
        cout << "2. 删除学生信息" << endl;
        cout << "3. 显示学生成绩表" << endl;
        cout << "4. 合并两个表" << endl;
        cout << "0. 退出程序" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            long num;
            char name[10];
            float score;
            cout << "请输入学生学号：";
            cin >> num;
            cout << "请输入学生姓名：";
            cin >> name;
            cout << "请输入学生成绩：";
            cin >> score;

            Student* student = new Student(num, name, score);   // 创建学生对象
            list.insert(student);                               // 插入学生信息到线性表
            cout << "学生信息已插入成功！" << endl;
        }
        else if (choice == 2) {
            long num;
            cout << "请输入要删除的学生学号：";
            cin >> num;
            list.remove(num);                                   // 删除学生信息
        }
        else if (choice == 3) {
            list.display();                                     // 显示学生成绩表
        }
        else if (choice == 4) {
            LinearList list2;
            // 向第二个线性表中插入学生信息
            long num;
            char name[10];
            float score;
            cout << "请输入学生学号：";
            cin >> num;
            cout << "请输入学生姓名：";
            cin >> name;
            cout << "请输入学生成绩：";
            cin >> score;

            Student* student = new Student(num, name, score);   // 创建学生对象
            list2.insert(student);                              // 插入学生信息到第二个线性表
            cout << "学生信息已插入成功！" << endl;

            LinearList mergedList = LinearList::mergeLists(list, list2);   // 合并两个线性表
            cout << "合并后的学生成绩表：" << endl;
            mergedList.display();                              // 显示合并后的学生成绩表
        }
        else if (choice == 0) {
            break;                                              // 退出程序
        }
        else {
            cout << "无效的选择，请重新输入！" << endl;
        }

        cout << endl;
    }

    return 0;
}