#include <iostream>


class vehicule
{
private:
    char marque;
    int year;
    double prix_ini;
    double val_act;
public:
    vehicule(char, int, double, double);
    ~vehicule();
    set_val_act(int);
    get_info();

}



vehicule::vehicule(char m, int y, double prix, double val) : ... {
    this->marque = m;
    this->year = y;
    this->prix_ini= prix;
    this->val_act = val ;
}

vehicule::set_val_act(int new_val) {
    val_act = new_val;
}
vehicule::get_info(){
    cout << "Ce vehicule est de marque : " << marque << "\nConstruit en : "<< year << "\nCout initial : "<<  prix_ini << "\nCout actuel :" << val_act;

}