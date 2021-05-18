class Chequera : public CtaBanc{
    private:
        double comision;
    public:
        //Constructores 
        Chequera();
        Chequera(int, double, double);
        //Getters
        double getComision() {return comision;}
        //Setters
        void setComision(double tempComision) {comision = tempComision;}
        //Metodos redefinidos
        bool retira(double);
        void mostrar();
};
//Constructores
Chequera :: Chequera() : CtaBanc(){
    comision = 0;
}
Chequera :: Chequera(int numCuenta, double saldo, double tempComision) : CtaBanc(numCuenta,saldo){
    comision = tempComision;
}
//Otros metodos
bool Chequera :: retira(double cantidad){
    if(saldo >= cantidad + comision){
        saldo -= cantidad + comision;
        return true;
    } else {
        return false;
    }
}
void Chequera :: mostrar(){
    cout << "Tu cuenta " << numCuenta << " tiene un saldo: " << saldo << " y una comision de: " << comision << endl;
}