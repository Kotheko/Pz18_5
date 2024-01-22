#include <iostream>
#include <string>

class Gamer
{
public:
    Gamer()
    {}

    Gamer(std::string _name, int _score) : name(_name), score(_score)
    {}

    std::string getName()
    {
        return name;
    }

    int getScore()
    {
        return score;
    }

private:
    std::string name;
    int score;
};

int main()
{
    int count;
    Gamer* arr;

    std::cout << "Сколько будет игроков?\n";
    std::cin >> count;

    arr = new Gamer[count];

    for (int i = 0; i < count; i++)
    {
        std::string name;
        int score;

        std::cout << "Имя " + std::to_string(i + 1) + "-го игрока:\n";
        std::cin >> name;

        std::cout << "Количество очков:\n";
        std::cin >> score;

        arr[i] = Gamer(name, score);
    }
    std::cout << "----------\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << arr[i].getName() << " " << arr[i].getScore() << std::endl;
    }
    std::cout << "----------\n";

    //Сортировка выбором (Selection sort)
    Gamer tmp;
    for (int i = 0; i < count - 1; i++)
    {
        int max = i;

        for (int j = i + 1; j < count; j++)
        {
            if (arr[j].getScore() > arr[max].getScore())
            {
                max = j;
            }
        }

        if (i != max)
        {
            tmp = arr[i];
            arr[i] = arr[max];
            arr[max] = tmp;
        }
    }

    for (int i = 0; i < count; i++)
    {
        std::cout << arr[i].getName() << " " << arr[i].getScore() << std::endl;
    }

    delete[] arr;
}