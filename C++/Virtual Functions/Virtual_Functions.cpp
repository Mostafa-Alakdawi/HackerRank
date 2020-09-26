#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};


class Professor:public Person{
    private:
        int publications;
        static int cur_id;
        int id;

    public:
        Professor():id{cur_id++}{
            //std::cout << "Hi"<<std::endl;
        }
        void getdata(){
            //std::cout << "Enter your name: "<< std::endl;
            std::cin >> this->name;
            //std::cout << "Enter your name: "<< std::endl;
            std::cin >> this->age;
            std::cin >> this->publications;
        }
        void putdata(){
            std::cout << this->name << " ";
            std::cout << this->age << " ";
            std::cout << this->publications << " ";
            std::cout << this->id << std::endl;
        }
};

class Student:public Person{
    private:
        int publications;
        vector<int> marks;
        static int cur_id;
        int id;

    public:
        Student():id{cur_id++}{
            marks = vector<int>(6,0);
            //cur_id++;
        }
        
        int marksSum(){
            int sum = 0;

            for(int index = 0; index < 6; index++){
                sum += marks[index];
            }

            return sum;
        }

        void getdata(){
            std::cin >> this->name;
            std::cin >> this->age;

            for(int index = 0; index < 6; index++)
                std::cin >> this->marks[index];
        }

        void putdata(){
            std::cout << this->name << " ";
            std::cout << this->age << " ";
            std::cout << this->marksSum() << " ";
            std::cout << this->id << std::endl;
        }
};

int Professor::cur_id {1};
int Student::cur_id {1};
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

