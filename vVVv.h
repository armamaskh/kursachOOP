#pragma once
#include<string>
#include <iostream>
class VAGON   //Класс, описывающий информацию о вагоне
{
private:
    std::string tip_vagona;    //тип вагона
    std::string famil_provodn;         //фамилия проводника
    std::string pr_nal_kondec;      //признак наличия кондиционера
    int num_vagona;           //номер вагона
    int chisl_mest;           // число мест
    int num_poezd;            // номер поезда
    int srok_ekspl;           // срок эксплуатации
public:
    //Конструкторы класса
    VAGON();
    VAGON(const VAGON& obj);
    VAGON(const std::string& _tip_vagona, const std::string& _famil_provodn, const std::string& _pr_nal_kondec, int _num_vagona, int _chisl_mest, int _num_poezd, int _srok_ekspl);
    //Методы получения доступа к значениям полей класса(геттеры)
    std::string get_tip_vagona() const;
    std::string get_famil_provodn() const;
    std::string get_pr_nal_kondec() const;
    int get_num_vagona() const;
    int get_chisl_mest() const;
    int get_num_poezd() const;
    int get_srok_ekspl() const;
    //Методы для задания значений полей класса(сеттеры)
    void set_tip_vagona(std::string new_tip_vagona);
    void set_famil_provodn(std::string new_famil_provodn);
    void set_pr_nal_kondec(std::string new_pr_nal_kondec);
    void set_num_vagona(int new_num_vagona);
    void set_chisl_mest(int new_chisl_mest);
    void set_num_poezd(int new_num_poezd);
    void set_srok_ekspl(int new_srok_ekspl);
    //Метод для вывода содержимого полей класса на экран
    void show() const;
};
