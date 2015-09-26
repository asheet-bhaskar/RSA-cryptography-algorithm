#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<string>
using namespace std;
int e=13,d,n,phi;
class rsa
{
public:
    int encrypt(int);           // encrypts a message
    int decrypt(int);           // decrypts a message
    int check_coprime(int,int);
    void decryption_key();      // evaluate decryption key
    unsigned int gcd (unsigned int n1, unsigned int n2);         /// gcd of two numbers
    int modulo(int,int,int);  // modular exponentiation
}obj;
unsigned int rsa ::gcd (unsigned int n1, unsigned int n2)   /// calculating greatest comman divisor of two numbers.
{
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}
int rsa ::modulo(int a,int b,int c)        /// This function calculates (ab)%c
{
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}
int rsa ::check_coprime(int j,int l)    /// function below finds wheather given two numbers are relatively prime or not.
{
    int flag =0;
    if(gcd(j,l)==1)
        flag=1;
    return flag;
}
void rsa :: decryption_key()  /// Function below calculates the decryption key
{ long long int k =0;
        d = (1+(k*phi))/e;

        while(((1+(k*phi))%e)!=0)
        {
            ++k;
            d = (1+(k*phi))/e;
        }
      cout<<d<<endl;
}
 int rsa ::encrypt(int a)          /// Function below encrypts a message
{
    int cipher=modulo(a,e,n);
    return cipher;
}
int rsa :: decrypt(int b) ///Function below decrypts a cipher
{
     int k=modulo(b,d,n);
    return(k);
}
int main()
{
    int p=43,q=59,t,i=0,cont=0;
    //cout<<"Enter two prime numbers p and q:\n";
    //cin>>p>>q;
    n=p*q;
    phi=(p-1)*(q-1);
    cout<<"n ="<<n<<"\n"<<"phi ="<<phi<<endl;
    //cout<<"Enter encryption key 'e'(1<e<"<<phi<<")\n";
    //cin>>e;
    t=obj.check_coprime(e,n);
    if(t!=1)
       exit(0);
    //calculation of decryption key 'd'
    obj.decryption_key();
    cout<<"public key is= ("<<e<<","<<n<<")\n private key is = ("<<d<<","<<n<<")\n";
    string word;
    cout << "Please enter text message without spaces\n";
    cin>>word;
  int siz=word.length();
    int D[siz],A[siz];
       while (i<word.length())    // While the string isn't at the end...
            {
             //cout<<int(word[x])<<","<<word[x]<<",\n  "<<obj.encrypt(int(word[x]))<<endl;
             char x=word.at(i);
              A[i]= obj.encrypt(int(x)); // Transform the char to int
                i++;
            }
        for(int i=0;i<word.length();i++)
        {
            D[i]=obj.decrypt(A[i]);
        }
    cout<<"\nEncrypted text is\n"<<endl;
        for(int i=0;i<word.length();i++)
            {
                cout<<char(A[i]);
            }
    cout<<"\n\ndecrypted text is\n"<<endl;
        for(int i=0;i<word.length();i++)
            {
                cout<<char(D[i]);
            }
     cout << "\n\ndone:\n";
return 0;
}
