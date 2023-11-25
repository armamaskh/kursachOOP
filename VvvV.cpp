//Файл VAGON.cpp - содержит реализацию методов класса VAGON
#include "vVVv.h"
using namespace std;
//Реализация конструкторов
VAGON::VAGON() : num_vagona(0), chisl_mest(0), num_poezd(0), srok_ekspl(0) {}
VAGON::VAGON(const VAGON& obj) : tip_vagona(obj.tip_vagona), famil_provodn(obj.famil_provodn), num_vagona(obj.num_vagona), pr_nal_kondec(obj.pr_nal_kondec), chisl_mest(obj.chisl_mest), num_poezd(obj.num_poezd), srok_ekspl(obj.srok_ekspl) {}
VAGON::VAGON(const string& _tip_vagona, const string& _famil_provodn, const string& _pr_nal_kondec, int _num_vagona, int _chisl_mest, int _num_poezd, int _srok_ekspl) : tip_vagona(_tip_vagona), famil_provodn(_famil_provodn), pr_nal_kondec(_pr_nal_kondec), num_vagona(_num_vagona), chisl_mest(_chisl_mest), num_poezd(_num_poezd), srok_ekspl(_srok_ekspl) {}
//Реализация методов получения доступа к значениям полей класса
string VAGON::get_tip_vagona() const { return tip_vagona; }
string VAGON::get_famil_provodn() const { return famil_provodn; };
string VAGON::get_pr_nal_kondec() const { return pr_nal_kondec; };
int VAGON::get_num_vagona() const { return num_vagona; };
int VAGON::get_chisl_mest() const { return chisl_mest; };
int VAGON::get_num_poezd() const { return num_poezd; };
int VAGON::get_srok_ekspl() const { return srok_ekspl; };
//Реализация методов для задания значений полей класса
void VAGON::set_tip_vagona(string new_tip_vagona) { tip_vagona = new_tip_vagona; }
void VAGON::set_famil_provodn(string new_famil_provodn) { famil_provodn = new_famil_provodn; };
void VAGON::set_pr_nal_kondec(string new_pr_nal_kondec) { pr_nal_kondec = new_pr_nal_kondec; };
void VAGON::set_num_vagona(int new_num_vagona) { num_vagona = new_num_vagona; };
void VAGON::set_chisl_mest(int new_chisl_mest) { chisl_mest = new_chisl_mest; };
void VAGON::set_num_poezd(int new_num_poezd) { num_poezd = new_num_poezd; };
void VAGON::set_srok_ekspl(int new_srok_ekspl) { srok_ekspl = new_srok_ekspl; };
//Реализация метода для вывода содержимого полей класса на экран
void VAGON::show()  const {
    cout << "ТИП ВАГОНА : " << tip_vagona << endl;
    cout << "ФАМИЛИЯ ПРОВОДНИКА : " << famil_provodn << endl;
    cout << "ПРИЗНАК НАЛИЧИЯ КОНДЕЦИОНЕРА : " << pr_nal_kondec << endl;
    cout << "НОМЕР ВАГОНА: " << num_vagona << endl;
    cout << "ЧИСЛО МЕСТ В ВАГОНЕ: " << chisl_mest << endl;
    cout << "НОМЕР ПОЕЗДА: " << num_poezd << endl;
    cout << "СРОК ЭКПЛУАТАЦИИ: " << srok_ekspl << endl;
}
