#include <iostream>
#include <cstdlib>

using namespace std;

long long EXPMOD(long long a, long long x, long long n){
 if(x==0){return 1;}
 else if(x%2==0){
   long long t=EXPMOD(a,x/2,n);
   return (t*t)%n;
  } 
 else{
   long long t=EXPMOD(a,x-1,n);
   a=a%n;
   return (t*a)%n;
 }
}

long long EXP(long long a,long long x){
 if(x==0){return 1;}
 else if(x%2==0){
   long long t=EXP(a,x/2);
   return (t*t);
  } 
 else{
   long long t=EXP(a,x-1);
   return (t*a);
 }
}

bool ES_COMPUESTO(long long a,long long n,long long t,long long u){
  long long x = EXPMOD(a,u,n);
  if(x==1 || x==n-1){return false;}
  for(int i=1;i<=t;i++){
    x=EXPMOD(x,2,n);
    if(x==n-1){return false;}
  }
  return true;
}

bool MILLER_RABIN(long long n, int s){
  long long t=0;
  long long u=n-1;
  while(u%2==0){
    u=u/2;
    t=t+1;
  }
  for(int j=1;j<=s;j++){
    long long a=rand()%(n-1)+2;
    if(ES_COMPUESTO(a,n,t,u)){return false;}
  }
  return true;
}
int main()
{
    int k = 2;  // Number of iterations
 
    cout << "primos de 3 cifras: \n";
    for (long long n = 100; n < 999; n++)
       if (MILLER_RABIN(n, k)==true)
          cout << n << " ";
    cout<<"\n"<<"\n";
    cout << "primos de 4 cifras: \n";
    for (long long n = 1000; n < 9999; n++)
       if (MILLER_RABIN(n, k)==true)
          cout << n << " ";
    cout<<"\n"<<"\n";
    cout << "primos de 5 cifras: \n";
    for (long long n = 10000; n < 99999; n++)
       if (MILLER_RABIN(n, k)==true)
          cout << n << " ";
 
    return 0;
}
