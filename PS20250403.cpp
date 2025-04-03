#include <iostream>

using namespace std;

class Animal
{
    // 클래스 에서 사용할 필드(변수)
private:
    int food;
    int weight;

    // 클래스에서 사용할 메서드!
public:
    void set_animal(int _food, int _weight)
    {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc)
    {
        food += inc;
        weight += (inc / 3);
    }
    void view_stat()
    {
        cout << "food : " << food << endl;
        cout << "weight : " << weight << endl;
    }
};

int main()
{
    Animal animal1;
    Animal animal; // 클래스를 통해서 인스턴스 생성!
    animal1.set_animal(50, 1000);
    animal.set_animal(100, 200);

    animal1.view_stat();
    animal.view_stat();

    animal.increase_food(300);
    animal.view_stat();

    return 0;
}