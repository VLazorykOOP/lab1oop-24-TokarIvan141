#include <iostream>
#include <limits>
using namespace std;

// ================= Завдання 1 =================
// Опис ходу виконання:
// 1. Вводимо розмір масиву size.
// 2. Перевіряємо, чи розмір коректний (більший за 0).
// 3. Динамічно створюємо масив та вводимо його елементи.
// 4. Шукаємо перший додатний елемент та запам'ятовуємо його позицію.
// 5. Якщо знайдено, видаляємо його, зсуваючи всі наступні елементи.
// 6. Оновлюємо розмір масиву.
// 7. Виводимо оновлений масив.
// 8. Видаляємо динамічний масив для уникнення витоку пам'яті.
void task1()
{
    cout << "\n================= Task 1 ================\n";

    int size;
    cout << "Array size: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid array size!\n";
        return;
    }

    int* arr = new int[size];
    cout << "Input array elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int pos = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    cout << "\nResult:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    delete[] arr;
}

// ================= Завдання 2 =================
// Опис ходу виконання:
// 1. Вводимо розмір масиву size.
// 2. Перевіряємо, чи розмір коректний (більший за 0).
// 3. Динамічно створюємо масив та вводимо його елементи.
// 4. Шукаємо перший нуль у масиві.
// 5. Якщо нуль знайдено, шукаємо мінімальне додатне число після нього.
// 6. Виводимо знайдене значення або повідомлення про його відсутність.
// 7. Видаляємо динамічний масив для уникнення витоку пам'яті.
void task2()
{
    cout << "\n================= Task 2 ================\n";

    int size;
    cout << "Array size: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid array size!\n";
        return;
    }

    int* arr = new int[size];
    cout << "Array elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int zero_idx = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zero_idx = i;
            break;
        }
    }

    int min_val = numeric_limits<int>::max();
    if (zero_idx != -1)
    {
        for (int i = zero_idx + 1; i < size; i++)
        {
            if (arr[i] > 0 && arr[i] < min_val)
                min_val = arr[i];
        }
    }

    cout << ((min_val == numeric_limits<int>::max())
    ? "No positive numbers found after zero\n"
    : "Minimum positive: " + to_string(min_val) + "\n\n");

    delete[] arr;
}

// ================= Завдання 3 =================
// Опис ходу виконання:
// 1. Вводимо розміри масивів A (не більше 400) та B (не більше 200).
// 2. Перевіряємо коректність введених розмірів.
// 3. Динамічно створюємо масиви та вводимо їхні елементи.
// 4. Шукаємо симетричну різницю (елементи, які є лише в одному з масивів).
// 5. Формуємо масив C, уникаючи повторень елементів.
// 6. Виводимо отриманий масив C.
// 7. Видаляємо динамічні масиви для уникнення витоку пам'яті.

// Функція перевіряє, чи міститься значення val у масиві arr розміром size.
// Якщо значення знайдено, повертає true, інакше — false.
bool contains(int* arr, int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return true;
    }
    return false;
}

void task3()
{
    cout << "\n================= Task 3 ================\n";

    int n, m;
    cout << "Size of A (<=400): ";
    cin >> n;

    if (n <= 0 || n > 400)
    {
        cout << "Invalid size for A!\n";
        return;
    }

    cout << "Size of B (<=200): ";
    cin >> m;

    if (m <= 0 || m > 200)
    {
        cout << "Invalid size for B!\n";
        return;
    }

    int* A = new int[n];
    int* B = new int[m];

    cout << "Elements of A:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Elements of B:\n";
    for (int i = 0; i < m; i++)
        cin >> B[i];

    int* C = new int[n + m];
    int c_size = 0;

    for (int i = 0; i < n; i++)
    {
        if (!contains(B, m, A[i]) && !contains(C, c_size, A[i]))
        {
            C[c_size++] = A[i];
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (!contains(A, n, B[i]) && !contains(C, c_size, B[i]))
        {
            C[c_size++] = B[i];
        }
    }

    cout << "\nSymmetric difference:\n";
    for (int i = 0; i < c_size; i++)
    {
        cout << C[i] << "\t";
        if ((i + 1) % 5 == 0)
            cout << "\n";
    }
    cout << "\n\n";

    delete[] A;
    delete[] B;
    delete[] C;
}

// ================= Головне меню =================
int main() {

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Task #1 (Remove the first positive number)\n";
        cout << "2. Task #2 (Minimum positive number after zero)\n";
        cout << "3. Task #3 (Symmetric difference)\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
