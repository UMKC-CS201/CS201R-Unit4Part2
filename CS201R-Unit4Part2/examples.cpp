#include "examples.h"

void example1() {
    //IO USING CIN COMMAND
    cout << "\nEXAMPLE 1: CIN VS GETLINE\n";
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "\nEnter string 2: ";
    cin >> s2;
    cout << "\ns1 =  " << s1 << " & s2 = " << s2 << endl << endl;

    //IO USING GETLINE
    cout << "TRYING AGAIN: \nEnter string 1: ";
    getline(cin, s1);
    cout << "\nEnter string 2: ";
    getline(cin, s2);
    cout << "s1 = " << s1 << " & s2 = " << s2 << endl << endl;

    cout << "Enter 2 strings (return between strings): \n";
    getline(cin, s1);
    getline(cin, s2);
    cout << "S1= " << s1 << endl;
    cout << "S2= " << s2 << endl << endl << endl;

}

void example2() {
    //ISSUES COMBINING DIFFERENT TYPES OF STREAM INPUT
    //PAY ATTENTION TO WHAT IS LEFT IN THE BUFFER!
    cout << "\nEXAMPLE 2: CAREFUL OF BUFFERS\n";
    int age;
    string name;
    char gender;

    cout << "Enter Your Age: ";
    cin >> age;              //get age

    cout << "Enter Name: ";
    getline(cin, name);      //get what is left in buffer

    cout << "Enter Gender: ";
    cin >> gender;

    cout << "\nName = " << name << endl;
    cout << "Age    = " << age << endl;
    cout << "Gender = " << gender << endl;

    //CIN.INGORE:  CLEARS BUFFER FOR 80 CHARACTERS OR UNTIL A 'RETURN' IS FOUND
    cin.ignore(80, '\n');                 //getline(cin,string1) will also work.
    cout << "\n\nTRYING AGAIN:\nEnter Your Age: ";
    cin >> age;              //get age
    cin.ignore(80, '\n');

    cout << "Enter Name: ";
    getline(cin, name);      //get what is left in buffer

    cout << "Enter Gender: ";
    cin >> gender;

    cout << "\nName = " << name << endl;
    cout << "Age    = " << age << endl;
    cout << "Gender = " << gender << endl << endl << endl;
    cin.ignore(80, '\n');  //clear for next example
}

void example3() {
    cout << "\nEXAMPLE 3: REMOVE UPPER CASE\n";
    //Using cin.get to get a character at a time
    //Read a string & get rid of any uppercase letters
    char c;
    cout << "Enter a string: ";
    cin.get(c);

    while (c != '\n') {
        if (!isupper(c))
            cout << c;
        cin.get(c);
    }
    cout << endl << endl;
}

void example4() {
    cout << "\nEXAMPLE 4: REMOVE NON-CHARACTERS\n";
    //Read a string & create a new string with only alphabetic characters
    string inString, outString = "";
    cout << "Enter a string: ";
    getline(cin, inString);

    for (unsigned int i = 0; i < inString.length(); i++) {
        if (isalpha(inString[i]))
            outString += inString[i];
    }
    cout << outString << endl << endl;
}

void example5() {
    cout << "\nEXAMPLE 5: REMOVE CERTAIN CHARACTERS\n";
    //Read a string & create a new string with only alphabetic characters
    string sentence = "Standard C++ Library";
    int plus = sentence.find('+');
    sentence.erase(plus, 2);
    cout << sentence << endl << endl;
}


void example6() {
    cout << "\nEXAMPLE 6: COMPARING STRINGS\n";
    //Read a string & create a new string with only alphabetic characters
    string s1 = "abc";
    string s2 = "abd";
    string s3 = "abcd";
    string s4 = "ABC";
    if (s1 > s2)  cout << "s1 is greater\n";
    else  cout << "s2 is greater\n";
    if (s1 > s3)  cout << "s1 is greater\n";
    else  cout << "s3 is greater\n";
    if (s1 > s4)  cout << "s1 is greater\n";
    else  cout << "s4 is greater\n";
}

void example7() {
    cout << "\nEXAMPLE 7: Using Structs with Vector\n";
    //create a Struct to hold information:
    struct Person {
        string name;
        int age;
    };
    //CIN.INGORE:  CLEARS BUFFER FOR 80 CHARACTERS OR UNTIL A 'RETURN' IS FOUND
    string clearStr;
    Person p1;
    vector<Person> people;

    cout << "\n\nEnter name: ";
    getline(cin, p1.name);      //get what is left in buffer
    cout << "Enter age: ";
    cin >> p1.age;              //get age
    getline(cin, clearStr);

    Person p2{ "Bugs Bunny", 25 };
    people.push_back(p1);
    people.push_back(p2);

    for (auto i : people)
        cout << "Name: " << i.name << " : " << i.age << endl;
}