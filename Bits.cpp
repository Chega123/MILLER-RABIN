#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long EXPMOD(unsigned long long a, unsigned long long x, unsigned long long n){
 if(x==0){return 1;}
 else if(x%2==0){
   unsigned long long t=EXPMOD(a,x/2,n);
   return (t*t)%n;
  } 
 else{
   unsigned long long t=EXPMOD(a,x-1,n);
   a=a%n;
   return (t*a)%n;
 }
}

unsigned long long EXP(unsigned long long a,unsigned long long x){
 if(x==0){return 1;}
 else if(x%2==0){
   unsigned long long t=EXP(a,x/2);
   return (t*t);
  } 
 else{
   unsigned long long t=EXP(a,x-1);
   return (t*a);
 }
}

bool ES_COMPUESTO(unsigned long long a,unsigned long long n,unsigned long long t,unsigned long long u){
  unsigned long long x = EXPMOD(a,u,n);
  if(x==1 || x==n-1){return false;}
  for(int i=1;i<=t;i++){
    x=EXPMOD(x,2,n);
    if(x==n-1){return false;}
  }
  return true;
}

bool MILLER_RABIN(unsigned long long n, int s){
  unsigned long long t=0;
  unsigned long long u=n-1;
  while(u%2==0){
    u=u/2;
    t=t+1;
  }
  for(int j=1;j<=s;j++){
    unsigned long long a=rand()%(n-1)+2;
    if(ES_COMPUESTO(a,n,t,u)){return false;}
  }
  return true;
}

unsigned long long RANDOMBITS(int b){
  unsigned long long n = rand() % EXP(2,b-1);
  unsigned long long m = EXP(2,b-1)+1;
  n=n|m;
  return n;
}

unsigned long long RANDOMGEN_PRIMOS(int b){
  int s=0;
  unsigned long long n=RANDOMBITS(b);
  while(MILLER_RABIN(n,s)==false){
    n=n+2;
  }
  return n;
}

int main() {
  unsigned long long a[10];
  for(int i=0;i<10;i++){
    a[i]=RANDOMGEN_PRIMOS(16);
  }


  
  while(true){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(i!=j){
          if(a[i]==a[j]){
            a[i]=RANDOMGEN_PRIMOS(16);
          }
        }
      }
    }
    break;
  }
  cout << "Numero primos de 16 bits:" << endl;
  for(int i=0;i<10;i++){
    cout<< a[i] << endl;
  }
  cout<< endl;
  
  for(int i=0;i<10;i++){
    a[i]=RANDOMGEN_PRIMOS(32);
  }
  while(true){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(i!=j){
          if(a[i]==a[j]){
            a[i]=RANDOMGEN_PRIMOS(32);
          }
        }
      }
    }
    break;
  }
  cout << "Numero primos de 32 bits:" << endl;
  for(int i=0;i<10;i++){
    cout<< a[i] << endl;
  }
  cout<< endl;


  for(int i=0;i<10;i++){
    a[i]=RANDOMGEN_PRIMOS(64);
  }
  while(true){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(i!=j){
          if(a[i]==a[j]){
            a[i]=RANDOMGEN_PRIMOS(64);
          }
        }
      }
    }
    break;
  }
  cout << "Numero primos de 64 bits:" << endl;
  for(int i=0;i<10;i++){
    cout<< a[i] << endl;
  }
  cout<< endl;
}
