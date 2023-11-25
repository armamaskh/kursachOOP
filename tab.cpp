// Файл главной программы
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include "vVVv.h"
using namespace std;
//Вектор, содержащий объекты класса VAGON
vector<VAGON> List;
void menu();        //Функция прорисовки меню
void hline();       //Функция, рисующая горизонтальную линию
int find(vector<VAGON>L, string key);
void vvod(vector<VAGON>& L);      //Функция ввода данных
void edit(vector<VAGON>& L);      //Функция редактирования данных
void vivod(vector<VAGON>L);       //Функция вывода данных
void searchA(vector<VAGON>L);      //Функция поиска данных
void searchB(vector<VAGON>L);      //Функция поиска данных
void searchC(vector<VAGON>L);      //Функция поиска данных
void del(vector<VAGON>& L);       //Функция удаления данных
//Главная функция программы
int main()
{
    setlocale(LC_ALL, " ");
    int n = 0;
    //Цикл обработки действий пользователя
    while (n != 8)
    {
        menu();
        cin >> n;
        switch (n)
        {
        case 1: vvod(List); break;
        case 2: vivod(List); break;
        case 3: edit(List); break;
        case 4: searchA(List); break;
        case 5: searchB(List); break;
        case 6: searchC(List); break;
        case 7: del(List); break;
        case 8: break;
        default: cout << "Неверный вариант выбора" << endl;
        }
    }
}
//Реализация функции прорисовки меню
void menu()
{
    cout << endl << "             МЕНЮ     " << endl;
    cout << "       1. ВВОД ДАННЫХ" << endl;
    cout << "       2. ВЫВОД ДАННЫХ" << endl;
    cout << "       3. РЕДАКТИРОВАНИЕ ДАННЫХ" << endl;
    cout << "       4. ПОИСК(А) по сроку экплуатации" << endl;
    cout << "       5. ПОИСК(Б) по фамилии проводника" << endl;
    cout << "       6. ПОИСК(В) по наличию кондиционеров" << endl;
    cout << "       7. Удаление данных" << endl;
    cout << "       8. ВЫХОД" << endl;
    cout << "Введите номер пункта меню для дальнейшей работы" << endl;
}
//Реализация функции ввода данных
void vvod(vector<VAGON>& L)
{
    char choise;        //Переменная для запоминания выбора пользователя
    string tip_vagona, famil_provodn, pr_nal_kondec;   //Переменные для заполнения данных
    int num_vagona, chisl_mest, num_poezd, srok_ekspl;
    bool t = true;
    while (t)
    {
        cout << "введите тип вагона---> ";
        while (cin.get() != '\n');
        getline(cin, tip_vagona);
        cout << "введите фамилию проводника---> ";
        getline(cin, famil_provodn);
        cout << "введите признак наличия кондиционера---> ";
        getline(cin, pr_nal_kondec);
        cout << "введите номер вагона---> ";
        cin >> num_vagona;
        cout << "введите число мест в вагоне---> ";
        cin >> chisl_mest;
        cout << "введите номер поезда---> ";
        cin >> num_poezd;
        cout << "введите срок эксплуатации вагона(сколько лет)---> ";
        cin >> srok_ekspl;
        //Добавление нового элемента в вектор
        L.push_back(VAGON(tip_vagona, famil_provodn, pr_nal_kondec, num_vagona, chisl_mest, num_poezd, srok_ekspl));
        //Запрос подтверждения на ввод новой записи
        while (true) {
            cout << "Продолжить ввод? Введите 1 - если да, 0 - если нет" << endl;
            cin >> choise;
            //Программа находится в режиме ожидания, пока пользователь не введет 'д' или 'н'
            if (choise == '1' || choise == '0')
                break;
        }
        if (choise == '0')
            t = false;
    }
}
           
        //Если пользователь ввел 'н', то выходим из цикла
//Реализация функции вывода данных

void vivod(vector<VAGON>L){
    //Прорисовка шапки таблицы
    cout << "                                            ВАГОНЧИКИ       " << endl;
    hline();
    cout << "| Тип  Вагона | Фамилия Провод | Признак нал.кондец | №вагона | Числ.мес | №поезд | Срок эксп |" << endl;
    hline();
    //Вывод на экран элементов вектора
    for (int i = 0; i < L.size(); i++)
    {
        cout << "| " << setw(11) << L[i].get_tip_vagona() << " | "
            << setw(13) << L[i].get_famil_provodn() << "  |" << setw(19) << L[i].get_pr_nal_kondec() << " | "
            << setw(7) << L[i].get_num_vagona() << " | " << setw(6) << L[i].get_chisl_mest() << " | "
            << setw(8) << L[i].get_num_poezd() << " | " << setw(9) << L[i].get_srok_ekspl() << " |" << endl;
    }
    hline();}

//Реализация функции поиска элемента по ключу
int find(vector<VAGON>L, string key) {
    for (int i = 0; i < L.size(); i++)
    {
        if (L[i].get_tip_vagona() == key)
        {
            return i;
        }
    }
    return -1;
}
//Реализация функции редактирования элемента вектора
void edit(vector<VAGON>& L)
{
    //Переменные для заполнения данных 
    string tip_vagona;
    string famil_provodn, pr_nal_kondec;
    int num_vagona, chisl_mest, num_poezd, srok_ekspl;
    cout << "введите тип вагона: " << endl;
    while (cin.get() != '\n');
    getline(cin, tip_vagona);
    //Поиск по номеру зачетки студента в векторе
    int ind = find(L, tip_vagona);
    //Если нашлась информация - вывод найденных сведений и
    //предложение отредактировать нужные поля
    if (ind != -1)
    {
        cout << endl << "Данные найдены" << endl;
        L[ind].show();
        cout << endl << "Введите новый тип вагона или 0, если хотите оставить старый" << endl;
        getline(cin, tip_vagona);
        if (tip_vagona != "0")
            L[ind].set_tip_vagona(tip_vagona);
        cout << "введите фамилию проводника или 0, если хотите оставить старые" << endl;
        getline(cin, famil_provodn);
        if (famil_provodn != "0")
            L[ind].set_famil_provodn(famil_provodn);
        cout << "введите новый признак наличия кондиционера или 0, если хотите оставить старую" << endl;
        getline(cin, pr_nal_kondec);
        if (pr_nal_kondec != "0")
            L[ind].set_pr_nal_kondec(pr_nal_kondec);
        cout << "введите новый номер вагона или 0, если хотите оставить старый" << endl;
        cin >> num_vagona;
        if (num_vagona != 0)
            L[ind].set_num_vagona(num_vagona);
        cout << "Введите новое число мест или 0, если хотите оставить старый" << endl;
        cin >> chisl_mest;
        if (chisl_mest != 0)
            L[ind].set_chisl_mest(chisl_mest);
        cout << "Введите новый номер поезда или 0, если хотите оставить старый" << endl;
        cin >> num_poezd;
        if (num_poezd != 0)
            L[ind].set_num_poezd(num_poezd);
        cout << "Введите новый срок эксплуатации или 0, если хотите оставить старый" << endl;
        cin >> srok_ekspl;
        if (chisl_mest != 0)
            L[ind].set_srok_ekspl(srok_ekspl);
        cout << endl << "Редактирование окончено" << endl;
    }
    else
        cout << "Данные для редактирования не найдены" << endl;
}
//Реализация функции поиска по кол-ву лет эксплуатации 
void searchA(vector<VAGON>L)
{
    int srok_ekspl;
    cout << "Введите срок эксплуатации(сколько лет)---> ";
    cin >> srok_ekspl;
    cout << endl << "Результаты поиска:" << endl;
    for (int i = 0; i < L.size(); i++)
    {
        if (L[i].get_srok_ekspl() > srok_ekspl)
            L[i].show();
    }
}
//Реализация функции поиска информации по тиму вагона
void searchB(vector<VAGON>L)
{
    string famil_provodn;
    cout << "введите фамилию проводника--->" << endl;
    while (cin.get() != '\n');
    getline(cin, famil_provodn);
    cout << endl << "Результаты поиска:" << endl;
    for (int i = 0; i < L.size(); i++)
    {
        string famil_provodn_st = L[i].get_famil_provodn();
        if (famil_provodn_st.find(famil_provodn) != famil_provodn_st.npos)
            L[i].show();
    }
}
//Реализация функции поиска по наличию кондиционеру
void searchC(vector<VAGON>L)
{
    string pr_nal_kondec;
    cout << "введите признак наличия кондиционера(да/нет)" << endl;
    while (cin.get() != '\n');
    getline(cin, pr_nal_kondec);
    cout << endl << "Результаты поиска:" << endl;
    for (int i = 0; i < L.size(); i++)
    {
        string pr_nal_kondec_st = L[i].get_pr_nal_kondec();
        if (pr_nal_kondec_st.find(pr_nal_kondec) != pr_nal_kondec_st.npos)
            L[i].show();
    }
}
//Реализация функции удаления элемента из вектора
void del(vector<VAGON>& L)
{
    string key;
    cout << "Введите тип вагона для удаления----->";
    while (cin.get() != '\n');
    getline(cin, key);
    cout << endl;
    int ind = find(L, key);
    if (ind != -1)
    {
        L.erase(L.begin() + ind);
        cout << "ИНФОРМАЦИЯ удалена" << endl;
    }
    else
        cout << "Данные для удаления не найдены" << endl;
}
//Функция прорисовки горизонтальной линии
void hline() {
    const int m = 95;
    for (int i = 0; i < m; i++)
        cout << "-";
    cout << endl;
}

