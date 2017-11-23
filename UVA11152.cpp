#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double a, b, c, areaTri, areaCirG, areaCirP, s, radio, pi = acos(-1);
    while(true){
      cin >> a >> b >> c;
      if(cin.fail()) break;
      s = (a+b+c)/2;
      areaTri = sqrt(s*(s-a)*(s-b)*(s-c)); //Formula de Heron
      radio = a*b*c/(4*areaTri); //Formula de Heron (Triangulo inscrito)
      areaCirG = pow(radio, 2) * pi;
      radio = areaTri / s; //Formula de Heron (Triangulo circunscrito)
      areaCirP = pow(radio, 2) * pi;
      areaCirG -= areaTri;
      areaTri -= areaCirP;
      cout << fixed;
      cout << setprecision(4);
      cout << areaCirG << " " << areaTri << " " << areaCirP << endl;
    }
    return 0;
}