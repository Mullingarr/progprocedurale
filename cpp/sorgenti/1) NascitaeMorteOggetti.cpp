#include <iostream>
#include <string>

class Demo
{
public:
    Demo(const char* nm);
    ~Demo();
private:
    char name[20];
};

Demo::Demo(const char* nm)
{
    strncpy(name, nm, 20);
    std::cout<<"Costruttore chiamato per"<<name<<'\n';
    
}

Demo::~Demo()
{
    std::cout<<"Distruttore chiamato per"<<name<<'\n';
}

void func()
{
    Demo OggettoLocaleFun("OggettoLocaleFun");
    static Demo OggettoStatico("OggettoStatico");
    std::cout<<"Dentro func\n";
}

Demo OggettoGlobale("OggettoGlobale");

int main(int argc, const char * argv[]) {
    // insert code here...
    Demo OggettoLocaleMain("OggettoLocale Main");
    std::cout << "Dentro main prima di chiamare func\n";
    func();
    std::cout << "Dentro main prima di chiamare func\n";
    return 0;
}
