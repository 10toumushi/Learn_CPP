// #pragma once
#ifndef _TEST_FUNCTION_H_
#define _TEST_FUNCTION_H_

class Ref {
public:
    int num_;
    int& GetRefNum();
    // int& GetRefNum2() {int x = 0; return x;}    // warning発生
private:
    int num2_ = 10;
};


//////// 前方宣言 ////////
class Base;
class Sub;
class Sub2;



//////// クラス宣言 ////////
class TestFunction {
private:
    int foo(int a = 0, int b = 0);
    void foo(Ref& a);
    static int ber(int a = 0, int b = 0);
    void FuncArgvBase(Base b);
    void FuncArgvSub(Sub s);
    void FuncArgvSub2(Sub2 s2);
    void FuncArgvBasePtr(Base* b);
    void FuncArgvSubPtr(Sub* s);
    void FuncArgvSub2Ptr(Sub2* s2);
    void FuncArgvBaseRef(Base& b);
    void FuncArgvSubRef(Sub& s);
    void FuncArgvSub2Ref(Sub2& s2);

public:
    void CheckConstractorAndDestractor();
    void CheckObjectSubstitution();
    void CheckTypeInfo();
    void CheckDecltype();
    void CheckNumOfArrayElement();
    void CheckObjectArray();
    void CheckObjecPointer();
    void CheckNewAndDelete();
    void CheckNewHandler();
    void CheckOperatorNewAndDelete();
    void CheckDynamicArrayOfObject();
    void CheckCopyConstractor();
    void CheckStaticMember();
    void CheckObjectReference();
    void CheckObjectReference2();
    void CheckInheritance();
    void CheckInheritance2();
    void CheckSubClassUpcast();
    void CheckHiding();
    void CheckOverride();
    void CheckObjectSlicing();
    void CheckMultiInheritance();

};



#endif // _TEST_FUNCTION_H_
