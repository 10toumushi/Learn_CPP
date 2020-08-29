#include <iostream>
#include "BasicClass.h"
#include "TestFunction.h"
using namespace std;


int main(int argc, char **argv) {
    TestFunction obj;

    obj.CheckConstractorAndDestractor();

    obj.CheckObjectSubstitution();

    obj.CheckTypeInfo();

    obj.CheckDecltype();

    obj.CheckNumOfArrayElement();

    obj.CheckObjectArray();

    obj.CheckObjecPointer();
    
    obj.CheckNewAndDelete();

    // CheckNewHandler();

    obj.CheckOperatorNewAndDelete();

    // obj.CheckDynamicArrayOfObject();

    // CheckObjectReference();

    // CheckObjectReference2();


    // cout << "-------- Override --------" << endl;
    // obj_b.Getter();
    // obj_b.f();
    // obj_s.f();
    // g(&obj_b);
    // g(&obj_s);
    // cout << endl;

    // obj_b.PrintBaseMember();
    // obj_s.PrintSubMember();

    // cout << "-------- Slicing --------" << endl;
    // g(obj_b);
    // g(obj_s);
    // cout << endl;



    // Base* p_b = new Base;


    cout << endl << "-------- Program end. --------" << endl;
}