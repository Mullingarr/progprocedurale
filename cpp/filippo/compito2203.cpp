#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

int main (void){

    int somma = 0;

    cout<<"inserire una serie di numeri reali."<<endl<<"Terminando la sequenza con uno 0"<<endl; 

    vector <int> v;
    int a;
    do{
        cin >> a;
        if(a > 0)
            v.push_back(a);
    }while(a > 0);

    /**
    cin >> a;
    while(a > 0){
       if(a > 0)
           v.push_back(a);
       cin >> a;
    }
     **/

    for(const auto& num: v){
        cout << num << " ";
    }
    //for(int i = 0; i < v.size(); i++)

    cout << "\n";
    cout << "Grandezza vettore inserito: " << v.size() << endl;
    
    for(int i=0; i < v.size(); i++){
        somma += v[i];
    }

    cout<<"la somma dei valori e' "<<somma  <<endl;
    float media = (float) somma / (float) v.size();
    
    //printf("%f\n", media);
    cout << media << endl;

    int max = 0;
    for(const auto& num : v){
        if(num > max)
           max = num;
    }

    cout << "max: " << max << endl;

    int min = v.at(0);
    for(const auto& num : v){
        if(min > num)
            min = num;
    }

    cout<< "min: " <<min<<endl;

    int n;
    cin >> n;

    vector<int> mul;
    vector<int> div;
    for(const auto& num : v){
        if(abs(n / num) == 0)
            mul.push_back(num);
    }

    for(const auto& num : v){
        if((num % n) == 0)
            div.push_back(num);
    }

    for(const auto& num : mul)
        cout << num << " ";

    cout << "\n";

    for(const auto& num : div)
        cout << num << " ";

    return 0; 

}