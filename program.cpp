#include <iostream>

using namespace std;

const int M = 20; // Розмір матриці
const int N = 20;

void Matrix22(); // Завдання 1

int diag_sum22(int matrix[M][N], const int row, const int col); // Сумує елементи які стоять на парних стовпцях
void show_matrix22(int matrix[M][N], const int row, const int col, const int sum); // Виводить матрицю та суму

void Matrix54(); // Завдання 2

void diag_sum54(int (&matrix)[M][N], const int row, const int col); // Змінює розташування від'ємного елемента на перше а перше на від'ємне
void show_matrix54(int matrix[M][N], const int row, const int col); // виводить матрицю завдання 2

void get_matrix(int matrix[M][N], int &row, int &col); // цей метод дозволяє вводити користувачу розмір та елементи матриці

int main()
{
    int menu = 1; // змінна для вибора завдання

    while (menu != 0) // це цикл який дозволяє обирати завдання багато разів, 0 це вихід
    {
        cout << "1. Matrix22" << endl; // виводимо просте меню
        cout << "2. Matrix54" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter menu: ";

        cin >> menu; // дозволяємо користувачу вводити номер завдання

        switch (menu) // що обрав користувач?
        {
            case 1:
                Matrix22();
                break;
            case 2:
                Matrix54();
                break;
            case 0:
                break;
            default:
                cout << "Invalid menu!" << endl; // помилка
                break;
        }
    }

    system("pause"); // закінчення
    return 0;
}

void Matrix22()
{
    // просто завдання 1

    int matrix[M][N]; // матриця яка ограничена полями 20 на 20

    int row, col; // змінні за допомогою яких користувач буде огранічувати розмір свієї матриці

    get_matrix(matrix, row, col); // користувач вводить необхідні дані
    int sum = diag_sum22(matrix, row, col); // сума всіх парних стовпців
    show_matrix22(matrix, row, col, sum); // виводимо матрицю та суму
}

int diag_sum22(int matrix[M][N], const int row, const int col)
{
    int sum = 0; // змінна в якій зберігається сума

    for (int i = 0; i < row; i++) // лічильник рядків
        for (int j = 2; j < col; j+=2) // лічильник стовпців, кожне парне
            sum += matrix[i][j]; // сумуємо

    return sum; // повертаємо
}

void show_matrix22(int matrix[M][N], const int row, const int col, const int sum)
{
    for (int i = 0; i < row; i++) // ліильник рядків
    {
        for (int j = 0; j < col; j++) // лічильник стовпців
            cout << matrix[i][j] << " "; // виводимо елемент

        cout << endl; // новий рядок
    }

    cout << "Sum: " << sum << endl; // виводимо суму
}

void Matrix54()
{
    // просто завдання 2

    int matrix[M][N]; // матриця яка ограничена полями 20 на 20

    int row, col; // змінні за допомогою яких користувач буде огранічувати розмір свієї матриці

    get_matrix(matrix, row, col); // користувач вводить дані
    diag_sum54(matrix, row, col); // змінюємо місцями
    show_matrix54(matrix, row, col); // виводимо
}

void diag_sum54(int (&matrix)[M][N], const int row, const int col)
{
    for (int i = 0; i < row; i++) // лічильник рядків
        for (int j = 0; j < col; j++) // лічильник стовпців
            if (matrix[i][j] < 0) // умова якщо від'ємне
            {
                int element = matrix[i][0]; // змінна яка хранить перший елемент

                matrix[i][0] = matrix[i][j]; // змінюємо місцями
                matrix[i][j] = element;
            }
}

void show_matrix54(int matrix[M][N], const int row, const int col)
{
    for (int i = 0; i < row; i++) // лічильник рядків
    {
        for (int j = 0; j < col; j++) // лічильник стовпців
            cout << matrix[i][j] << " "; // виводимо елемент

        cout << endl; // новий рядок
    }
}

void get_matrix(int matrix[M][N], int &row, int &col)
{
    do
    {
        cout << "Enter row and column counts (1-20): "; // просимо ввести ограніченія
        cin >> row >> col;
    } while (row < 2 || row > M || col < 2 || col > N || row != col); // доки рядок або стовпець не будуть більше 2 та буде більше 20 фбо якщо вони співподають тоді коректно
    
    for (int i = 0; i < row; i++) // лічильник рядків
        for (int j = 0; j < col; j++) // лічильник стовпців
            cin >> matrix[i][j]; // користувач вводить елемент
}