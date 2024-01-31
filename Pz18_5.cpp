#include <iostream>
#include <string>

class Gamer
{
public:
    Gamer()
    {
        GenerateName();
        GenerateScore();
    }

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

    //Сортировка выбором
    static void SelectionSort(Gamer* l, Gamer* r)
    {
        for (Gamer* i = l; i < r; i++)
        {
            Gamer max = *i, * ind = i;
            for (Gamer* j = i + 1; j < r; j++)
            {
                if (j->getScore() > max.getScore())
                {
                    max = *j, ind = j;
                }
            }
            std::swap(*i, *ind);
        }
    }

private:
    void GenerateName()
    {
        int start = 1;
        int end = names->length();

        int index = std::rand() % (end - start + 1) + start;

        name = names[index];
    }

    void GenerateScore()
    {
        int start = 1;
        int end = 100;

        score = std::rand() % (end - start + 1) + start;
    }

private:
    std::string name;
    int score;
    std::string names[15] =
    {
        "Василий",
        "Эдуард",
        "Геннадий",
        "Глафира",
        "Елизавета",
        "Анатолий",
        "Анастасия",
        "Вячеслав",
        "Иннокентий",
        "Ярослав",
        "Елисей",
        "Константин",
        "Станислав",
        "Екатерина",
        "Татьяна"
    };
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
        //std::string name;
        //int score;

        //std::cout << "Имя " + std::to_string(i + 1) + "-го игрока:\n";
        //std::cin >> name;

        //std::cout << "Количество очков:\n";
        //std::cin >> score;

        //arr[i] = Gamer(name, score);

        arr[i] = Gamer();
    }
    std::cout << "----------\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << arr[i].getName() << " " << arr[i].getScore() << std::endl;
    }
    std::cout << "----------\n";

    //Сортировка выбором (Selection sort)
 /*   for (int i = 0; i < count - 1; i++)
    {
        int max = i;

        for (int j = i + 1; j < count; j++)
        {
            if (arr[j].getScore() > arr[max].getScore())
            {
                max = j;
            }
        }

        std::swap(arr[i], arr[max]);
    }*/

    arr->SelectionSort(arr, arr + count);

    for (int i = 0; i < count; i++)
    {
        std::cout << arr[i].getName() << " " << arr[i].getScore() << std::endl;
    }

    delete[] arr;
}