#include <iostream>
using namespace std;

class Car
{
private:
    int speed;
    int gas;
    // string color;

public:
    int getSpeed() const // const 를 붙이는 이유는!! 변수의 값을 건드리지 않는 메서드라는 선언!!!
    {
        return speed;
    }
    void setSpeed(int _speed)
    {
        speed = _speed;
    }
    void setGas(int _gas)
    {
        gas = _gas;
    }
    // void color(string _color)
    // {
    //     color = _color;
    // }
    void speedUp()
    {
        speed++;
        gas--;
    }
    void printAll() const
    {
        cout << "speed : " << speed << endl;
        cout << "gas : " << gas << endl;
        // cout << "color : " << color << endl;
    }
};

int main()
{
    Car car;
    Car car1;

    car.setSpeed(0);
    car.setGas(50);
    car1.setSpeed(0);
    car1.setGas(100);

    car.printAll();
    car1.printAll();

    car.speedUp();

    car.printAll();
    car1.printAll();
    return 0;
}