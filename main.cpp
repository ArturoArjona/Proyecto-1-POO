#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  //abrir archivo de entrada, salida e intemediario y leer codigo
   string entrada, salida;
   cout << "¿Cuál es el archivo que desea decodificar?"<< endl;
   cin >> entrada;
   cout << "¿Cómo desea que se llame el archivo de salida?"<< endl;
   cin >> salida;
   ifstream archEnt;
   archEnt.open(entrada.c_str());
   ofstream archInt;
   archInt.open("Intermediario.txt");
   ofstream archSal;
   archSal.open(salida.c_str());
   string a, b, c, d, e, f, g, h, i, j, mas, menos, por, entre;
   archEnt >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> mas >> menos >> por >> entre;
   //decodificar archivo
   string num1, op, num2, dig;
   int l1, l2;
   while(archEnt >> num1 >> op >> num2){
     l1=num1.length();
     l2=num2.length();
     int cont1, cont2;
     cont1=0;
     cont2=0;
     //decodifica el primer numero
     while(cont1<l1){
       dig=num1.substr(cont1,1);
       num1.erase(cont1,1);
       if(dig==a){
         num1.insert(cont1,"0");
       }
       else if(dig==b){
         num1.insert(cont1,"1");
       }
       else if(dig==c){
         num1.insert(cont1,"2");
       }
       else if(dig==d){
         num1.insert(cont1,"3");
       }
       else if(dig==e){
         num1.insert(cont1,"4");
       }
       else if(dig==f){
         num1.insert(cont1,"5");
       }
       else if(dig==g){
         num1.insert(cont1,"6");
       }
       else if(dig==h){
         num1.insert(cont1,"7");
       }
       else if(dig==i){
         num1.insert(cont1,"8");
       }
       else if(dig==j){
         num1.insert(cont1,"9");
       }
       cont1++;
     }
     //decodifica operador
     if(op==mas){
       op="+";
     }
     else if (op==menos){
       op="-";
     }
     else if (op==por){
       op="*";
     }
     else{
       op="/";
     }
     //decodifica segundo numero
     while(cont2<l2){
       dig=num2.substr(cont2,1);
       num2.erase(cont2,1);
       if(dig==a){
         num2.insert(cont2,"0");
       }
       else if(dig==b){
         num2.insert(cont2,"1");
       }
       else if(dig==c){
         num2.insert(cont2,"2");
       }
       else if(dig==d){
         num2.insert(cont2,"3");
       }
       else if(dig==e){
         num2.insert(cont2,"4");
       }
       else if(dig==f){
         num2.insert(cont2,"5");
       }
       else if(dig==g){
         num2.insert(cont2,"6");
       }
       else if(dig==h){
         num2.insert(cont2,"7");
       }
       else if(dig==i){
         num2.insert(cont2,"8");
       }
       else if(dig==j){
         num2.insert(cont2,"9");
       }
       cont2++;
     }
     //guarda numero en archivo intermedio
     archInt << op << "\t"<< num1 << "\t" << num2 << endl;
   }
   archInt.close();
   //leer operador y numero y guardarlo en el archivo de salida junto con la resolucion
   //abrimos archivo intermedio
   ifstream archIn;
   archIn.open("Intermediario.txt");
   int n1, n2, r;
   //resolvemos operacion
   while(archIn >> op >> n1 >>n2){
     if(op=="+"){
       r=n1+n2;
     }
     else if(op=="-"){
       r=n1-n2;
     }
     else if(op=="*"){
       r=n1*n2;
     }
     else{
       r=n1/n2;
     }
     //escribimos en archivo de salida
     archSal << "(" << n1 << ") " << op << " (" << n2 << ") = " << r << endl;
   }




   //cerramos archivos
   archIn.close();
   archEnt.close();
   archSal.close();

    return 0;
}
