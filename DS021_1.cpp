#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    double getAvg() const;

public:
    string name;
    string sid;
    int *score;
    void print() const;
};

double Student::getAvg() const
{
    return (double)(*score) / 3.00;
}
void Student::print() const
{
    cout << "[" << sid << "] " << name << endl;
    printf("The Average score is %.1f", getAvg());
}

int main()
{
    Student s1; // Student 클래스로 인스턴스 s1 을 만들기!!
    int kor, eng, math;
    int total = 0;
    cin >> s1.sid >> kor >> eng >> math;
    cin.ignore();
    getline(cin, s1.name);

    total = kor + eng + math;
    s1.score = &total;

    s1.print();
    return 0;
}