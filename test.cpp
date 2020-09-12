#include <iostream>
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

    // obj.CheckNewHandler();

    obj.CheckOperatorNewAndDelete();

    obj.CheckDynamicArrayOfObject();

    obj.CheckCopyConstractor();

    // obj.CheckStaticMember();

    // obj.CheckObjectReference();

    // obj.CheckObjectReference2();

    // obj.CheckInheritance();

    // obj.CheckInheritance2();

    // obj.CheckSubClassUpcast();

    // obj.CheckHiding();

    // obj.CheckOverride();

    // obj.CheckObjectSlicing();

    // obj.CheckMultiInheritance();

    cout << endl << "-------- Program end. --------" << endl;
}