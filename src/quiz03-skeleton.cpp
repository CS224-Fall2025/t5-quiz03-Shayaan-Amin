#include <iostream>
#include <string>
using namespace std;


class employee {
    protected:
        string name;
        double salary;
        static int employeeCount; 

    public:
        employee(string n,double s) : name(n), salary(s) {
            employeeCount++;
        }

        virtual void displayInfo() {
            cout << "naem:" <<name<<"salary:" << salary << endl;
        }

        static void showTotalEmployees() {
            cout << "total employees created:" << employeeCount << endl;
        }

        virtual ~employee() {} 
};
int employee::employeeCount = 0;

class Staff:public employee{
    private:
        string department;
    public:
        Staff(string n, double s,string dept="Staff") : employee(n,s), department(dept) {}

        void displayInfo() override{
            cout<< "name "<<name<<" salarary"<<salary<<endl;
        }
};

class Faculty:public employee{
    private:
        string department;
    public:
        Faculty(string n, double s,string dept="Faculty") : employee(n, s), department(dept) {}

        void displayInfo() override{
            cout<< "name "<<name<<" salarary"<<salary<<endl;
        }
};

int main(){
    int n;
    cin >> n;
    employee* employees[n];

    for (int i=0;i<n;i++){
        string type; 
        string name;
        double salary;
        cin>>type;
        cin>> name; 
        cin>> salary;
        if (type=="Staff") {
            employees[i] = new Staff(name, salary);
        } else if (type=="Faculty") {
            employees[i]=new Faculty(name, salary);
        } else {
            cout << "Invalid employee type" << endl;
            employees[i] = nullptr;
        }
    }
    for (int i=0;i<n;i++){
        if (employees[i]!=nullptr){
            employees[i]->displayInfo();
        }
    }
    employee::showTotalEmployees();
}

