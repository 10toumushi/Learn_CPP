// #pragma once
#ifndef _TEST_FUNCTION_H_
#define _TEST_FUNCTION_H_

class Ref{
public:
    int num_;
    int& GetRefNum();
    // int& GetRefNum2() {int x = 0; return x;}    // warning発生
private:
    int num2_ = 10;
};


class TestFunction {
private:
    int foo(int a = 0, int b = 0);
    void foo(Ref& a);
    static int ber(int a = 0, int b = 0);

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
    void CheckObjectReference();
    void CheckObjectReference2();
};



#endif // _TEST_FUNCTION_H_
