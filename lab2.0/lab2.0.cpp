#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
#include <array>
using namespace std;
class Proba {
private:
    char x;
    char *arr;
    int size;
    int size2;
    char word;
    int pos;
    set<char> myARR;
    set<char> myARR2;
public:
    void Set(int size) {
        this->size = size;
        arr = new char[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter of value for index " << i << ":" << endl;
            cin >> arr[i];
            myARR.insert(arr[i]);
            
        }
    }
    void Set2(int size2) {
        this->size2 = size2;
        arr = new char[size2];
        for (int i = 0; i < size2; i++) {
            cout << "Enter of value for index " << i << ":" << endl;
            cin >> arr[i];
            myARR2.insert(arr[i]);
            
        }
    }
    void Print() {
        cout << "Elements of plural number 1: ";
        for (auto& item : myARR) {
            cout << item << endl;
        }
        
    }
    void Print2() {
        cout << "Elements of plural number 2: ";
        for (auto& item : myARR2) {
            cout << item << endl;
        }
    }
    /*
    void Insert(char word) {
        myARR.insert(word);
        myARR2.insert(word);
        cout << "Elements of plural number 1: " << endl;
        for (auto& item : myARR) {
            cout << item;
        }
        cout << endl;
        cout << "Elements of plural number 2: "<<endl;
        for (auto& item : myARR2) {
            cout << item;
        }
        cout << endl;
    }
    */
    

    void merge(const Proba& other) {
        for (char word : other.myARR) {
            myARR.insert(word);
            cout << "union of sets" << endl;
        }
    }
    
    //оператор порівняння розмірів множин
    bool operator > (Proba pos) {
        if (size <= pos.size || size2 >= pos.size2) {
            return true;
        } else {
            return false;
        }
    }

    //оператор порівняння
    bool operator == (const Proba& other) const {
        return (myARR == other.myARR);
        return (myARR2 == other.myARR2);
    }
    
    Proba& operator=(const Proba& other) {
        if (this != &other) {
            myARR = other.myARR;
        }
        return *this;
    }

    void removeSet(char input) {
        myARR.erase(input); 
        for (auto& item : myARR) {
            cout << item << endl;
        }
    }
    void removeSet2(char input) {
        myARR2.erase(input);
        for (auto& item : myARR2) {
            cout << item << endl;
        }
    }
    
    ~Proba(){
        delete[] arr;
    }
};

int main()
{
    
    
    Proba sho, sho2;
    cout << "Input size: " << endl;
    int siz;
    int siz2;
    cin >> siz;
    sho.Set(siz);
    cout<<"----ARRAY2----" << endl;
    cout << "Input size: " << endl;
    cin >> siz2;
    sho2.Set2(siz2);
    sho.Print();
    sho2.Print2();
    cout << endl;
    set<char>myARR;
    set<char>myARR2;
    char word;
    cout<<"Input word: " << endl;
    cin >> word;
    //sho.Insert(word);
    //sho.operator>(siz > siz2);
    if (myARR > myARR2) {
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    cout<<"Input element of plural number 1 for find them: " << endl;
    char fin;
    cin >> fin;
    cout << "Input element of plural number 2 for find them: " << endl;
    char fin2;
    cin >> fin2;
    auto finder = myARR.find(fin);
    cout << "input char of plural: " << endl;
    char fincheck;
    cin >> fincheck;
    cout << "input char of plural: " << endl;
    auto finder2 = myARR2.find(fin2);
    char fincheck2;
    cin >> fincheck2;

    if (myARR.find(fincheck) != myARR.end()) {
        cout << "element " << fincheck << " finded!" << endl;
    }
    else {
        cout << "element " << fincheck << " not finded(" << endl;
    }
    if (myARR2.find(fincheck2) != myARR2.end()) {
        cout << "element " << fincheck2 << " finded!" << endl;
    }
    else {
        cout << "element " << fincheck2 << " not finded(" << endl;
    }
    cout<<"Delete element of plural 1 : " << endl;
    char del;
    cin >> del;
    cout<<"DELETED succesful!"<< endl;
    sho.removeSet(del);
    cout << endl;
    cout << "Delete element of plural 2 : " << endl;
    char del2;
    cin >> del2;
    cout << "DELETED succesful!" << endl;
    sho2.removeSet2(del2);
    cout << endl;
    cout<<"==================" << endl;
    sho.merge(sho2);
    if (sho == sho2) {
        cout << "Sets are equal" <<endl;
    }
    else {
        cout << "Sets are not equal" <<endl;
    }
    
    
    /*
    set<char> mySet;

    //add elements:
    mySet.insert('a');
    mySet.insert('b');
    mySet.insert('c');

    //overrun(перебір) elements plural
    cout<<"plural: " << endl;
    for (auto &item : mySet) { // : Set - це те, що ми будемо перебирати. item - це рахунок усіх елементів.
        cout<<item<<endl;
    }
    //output size plural(множини)
    mySet.size();
    cout << "Size: ";
    cout << mySet.size() << endl;

    */
    
    /*
    //масив
    set<string> myArray = { "Roman", "Andriy" ,"Igor", "Stepan" };
    //insert() - add elements
    //find() - search elements
    //erase - delete element
    //lower_bound - приймає параметр/число, яке ми шукаємо. Знайде перше значення, які він знайде
    //apper_bound - найде і верне наступне число після(яке більше) lower_bound
    //equal_range - приймає параметр, який зберігається в нашій колекції(myArray) і повертає діапазон чисел від apper_bound до lower_bound 
    // set/multiset - в set є тільки унікальні елементи. в multiset є повторювані числа

    auto finder = myArray.find("Roman");
    string input;
    cin >> input;
    if (myArray.find(input) != myArray.end()) {
        cout<<"element "<<input<<" finded!" << endl;
    } 
    else {
        cout<< "element " << input << " not finded(" <<endl;
    }
    myArray.erase("Roman");
    cout<<"Elements of Array: " << endl;
    for (auto& item : myArray) {
        cout<<item<<endl;
    }
    */
    
}