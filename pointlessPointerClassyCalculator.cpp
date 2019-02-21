#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;


void displayArray(int len, int A[]){
  std::cout << "\n El resultado de la conversion es: ";
  for(len = len-1; len>=0; len--){
    if(A[len]==15){
      std::cout << "F";
    }else if(A[len]==14){
      std::cout << "E";
    }else if(A[len]==13){
      std::cout << "D";
    }else if(A[len]==12){
      std::cout << "C";
    }else if(A[len]==11){
      std::cout << "B";
    }else if(A[len]==10){
      std::cout << "A";
    }else{
      std::cout <<A[len];
    }
  }
  std::cout << "\n\n";
}

class Calculadora{
  private:
    int *n1, *n2, *n3;
    int ans;
    int A[50];
    char *op;
    string str;
  public:
    void setN1(int *n1);
    void setN2(int *n2);
    void setOp(char *op);
    void convert();
    int* operate();
    void setStr(string *str);
};

void Calculadora::setStr(string *str){
  this->str=*str;
}

void Calculadora::setN1(int *n1){
  this->n1=n1;
}
void Calculadora::setN2(int *n2){
  this->n2=n2;
}
void Calculadora::setOp(char *op){
  this->op=op;
}
int* Calculadora::operate(){
  //suma
  if(*this->op=='+'){
    this->ans=*this->n1+*this->n2;
    n3=&ans;
    return n3;
  };
  //resta
  if(*this->op=='-'){
    this->ans=*this->n1-*this->n2;
    n3=&ans;
    return n3;
  };
  //division
  if(*this->op=='/'){
    this->ans=(*this->n1)/(*this->n2);
    n3=&ans;
    return n3;
  };
  //multiplicacion
  if(*this->op=='*'){
    this->ans=(*this->n1)*(*this->n2);
    n3=&ans;
    return n3;
  };
  //potencia
  if(*this->op=='^'){
    ans = *n1;
    for(int i=0; i<*n2-1; i++){
      ans = ans*(*n1);
    }
    n3 = &ans;
    return n3;
  }
  //factorial
  if(*this->op=='!'){
    ans=1;
    for(int i=1; i<=*n1; i++){
      ans = (ans)*i;
    }
    n3=&ans;
    return n3;
  }
  //binario a decimal
  if(*this->op=='b'){
    int temp = *n1, i=1;
    ans=0;
    while(temp>0){
      ans += (temp%10)*i;
      temp = temp/10;
      i = i*2;
    }
    n3=&ans;
    return n3;
  }
  //octal a decimal
  if(*this->op=='O'){
    int temp = *n1, i=1;
    ans=0;
    while(temp>0){
      ans += (temp%10)*i;
      temp = temp/10;
      i = i*8;
    }
    n3=&ans;
    return n3;
  }
  //hexa a decimal
  this->ans=0;
  int aum=1;
  if(*this->op=='H'){
    for(int i=(this->str.length())-1; i>=0; i--){
      if(str[i]=='1')
        ans+= 1*aum;
      if(str[i]=='2')
        ans+= 2*aum;
      if(str[i]=='3')
        ans+= 3*aum;
      if(str[i]=='4')
        ans+= 4*aum;
      if(str[i]=='5')
        ans+= 5*aum;
      if(str[i]=='6')
        ans+= 6*aum;
      if(str[i]=='7')
        ans+= 7*aum;
      if(str[i]=='8')
        ans+= 8*aum;
      if(str[i]=='9')
        ans+= 9*aum;
      if(str[i]=='A')
        ans+= 10*aum;
      if(str[i]=='B')
        ans+= 11*aum;
      if(str[i]=='C')
        ans+= 12*aum;
      if(str[i]=='D')
        ans+= 13*aum;
      if(str[i]=='E')
        ans+= 14*aum;
      if(str[i]=='F')
        ans+= 15*aum;
      aum=aum*16;
    }
    n3=&ans;
    return n3;
  }


}
void Calculadora::convert(){

  //decimal a binario
  if(*this->op=='d'){
    int i = 0;
    ans = *n1;
    while(ans>0){
      A[i] = ans%2;
      ans = ans/2;
      i++;
    }
    displayArray(i, A);
  }
  //decimal a octal
  if(*this->op=='o'){
    int i = 0;
    ans = *n1;
    while(ans>0){
      A[i] = ans%8;
      ans = ans/8;
      i++;
    }
    displayArray(i, A);
  }
  //decimal a hexadecimal
  if(*this->op=='h'){
    int i = 0;
    ans = *n1;
    while(ans>0){
      A[i] = ans%16;
      ans = ans/16;
      i++;
    }
    displayArray(i, A);
  }
}


int main(){
    Calculadora cal;
  int num1, num2, rep;
  int *p1, *p2, *p3;
  char ope;
  char *op;
  string hex;
  string *h;

  do {
    cout<<"Elija uno de los siguientes operadores:\n| + suma     |   - resta    |    * multiplicacion   |    / division   |\n| ^ potencia | ! factorial (solo toma en cuenta el primer numero ingresado) |\n| d decimal a binario | b binario a decimal |\n| o decimal a octal | O octal a decimal |\n| h decimal a hexadecimal | H hexadecimal a decimal |\n"<<endl;
    cin>>ope;
    op=&ope;
    cal.setOp(op);

    if(ope == '+' || ope == '-' || ope == '/' || ope == '*' || ope == '^' || ope == '!' || ope == 'b' || ope == 'O'){
      std::cout << "Ingrese el primer numero: " <<endl;
      cin>>num1;
      p1=&num1;
      cal.setN1(p1);

      cout<<"Ingrese el segundo numero: "<<endl;
      cin>>num2;
      p2=&num2;
      cal.setN2(p2);

      std::cout << "Resultado: " <<*cal.operate()<<endl;
    }else if(ope == 'H'){
      cout<<"Ingrese su valor hexadecimal a convertir: "<<endl;
      cin>>hex;
      h = &hex;
      cal.setStr(h);

      std::cout << "Resultado: " <<*cal.operate()<<endl;
    }else{
      std::cout << "Ingrese el primer numero: " <<endl;
      cin>>num1;
      p1=&num1;
      cal.setN1(p1);

      cout<<"Ingrese el segundo numero: "<<endl;
      cin>>num2;
      p2=&num2;
      cal.setN2(p2);

      cal.convert();
    }
    std::cout << "Ingrese \n0 para terminar \n1 para realizar una operacion " <<endl;
    cin>>rep;
  } while(rep!=0);
}
