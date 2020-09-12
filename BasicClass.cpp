#include <iostream>
#include "BasicClass.h"
using namespace std;


//////// 基底クラス定義 ////////
Base::Base(void) {
    cout << "Base class generated." << endl;
}

Base::Base(int base_int) {
    base_int_ = base_int;
}

Base::Base(int base_int, double base_double) {
    base_int_ = base_int;
    base_double_ = base_double;
}

Base::Base(const Base&) {
    cout << "Base class copied." << endl;
}

Base::~Base(void) {
    cout << "Base class deleted." << endl;
}

void Base::FuncWithVirtual(void) {
    cout << "Virtual func of Base." << endl;
}

void Base::FuncWithoutVirtual(void) {
    cout << "Non virtual func of Base." << endl;
}

void Base::PrintBaseMember(void) {
    cout << "Base member = " << private_int_ << endl;
}

void Base::BaseFunc(void) {
    cout << "Base Func" << endl;
}

void Base::SetInt(int base_int) {
    base_int_ = base_int;
}

void Base::GetInt(void) {
    cout << "base_int_ = " << base_int_ << endl;
}

void Base::Plus(void) {
    cout << "base_int_ + base_double_ = " << base_int_ + base_double_ << endl;
}

void Base::Print(int num) {
    cout << num << endl;
}


int Base::s_base_int_ = 123;

void Base::StaticBaseFunc(void) {
    cout << "s_base_int_ = " << s_base_int_ << endl;
}



//////// 派生クラス定義 ////////
Sub::Sub(void) {
    cout << "Sub class generated." << endl;
}

Sub::Sub(int sub_int) {
    sub_int_ = sub_int;
}

Sub::Sub(int sub_int, double sub_double) {
    sub_int_ = sub_int;
    sub_double_ = sub_double;
}

Sub::~Sub(void) {
    cout << "Sub class deleted." << endl;
}

void Sub::FuncWithVirtual(void) {
    cout << "Virtual func of Sub." << endl;
}

void Sub::FuncWithoutVirtual(void) {
    cout << "Non virtual func of Sub." << endl;
}

void Sub::PrintSubMember(void) {
    cout << "Sub member = " << private_int_ << endl;
}

void Sub::SubFunc(void) {
    cout << "Sub Func" << endl;
}

void Sub::SetInt(int sub_int) {
    sub_int_ = sub_int;
}

void Sub::GetInt(void) {
    cout << "sub_int_ = " << sub_int_ << endl;
}

void Sub::Plus(void) {
    cout << "sub_int_ + sub_double_ = " << sub_int_ + sub_double_ << endl;
}

void Sub::Print(std::string str) {
    cout << str << endl;
}

int Sub::s_sub_int_ = 456;

void Sub::StaticSubFunc(void) {
    cout << "s_sub_int_ = " << s_sub_int_ << endl;
}




//////// 派生クラス2定義 ////////
Sub2::Sub2(void) {
    cout << "Sub2 class generated." << endl;
}

Sub2::Sub2(int sub2_int) {
    sub2_int_ = sub2_int;
}

Sub2::Sub2(int sub2_int, double sub2_double) {
    sub2_int_ = sub2_int;
    sub2_double_ = sub2_double;
}

Sub2::~Sub2(void) {
    cout << "Sub2 class deleted." << endl;
}

void Sub2::FuncWithVirtual(void) {
    cout << "Virtual func of Sub2." << endl;
}

void Sub2::FuncWithoutVirtual(void) {
    cout << "Non virtual func of Sub2." << endl;
}

void Sub2::PrintSub2Member(void) {
    cout << "Sub2 member = " << private_int_ << endl;
}

void Sub2::Sub2Func(void) {
    cout << "Sub2 Func" << endl;
}

void Sub2::SetInt(int sub2_int) {
    sub2_int_ = sub2_int;
}

void Sub2::GetInt(void) {
    cout << "sub2_int_ = " << sub2_int_ << endl;
}

void Sub2::Plus(void) {
    cout << "sub2_int_ + sub2_double_ = " << sub2_int_ + sub2_double_ << endl;
}

void Sub2::Print(double num) {
    cout << num << endl;
}

int Sub2::s_sub2_int_ = 456;

void Sub2::StaticSub2Func(void) {
    cout << "s_sub2_int_ = " << s_sub2_int_ << endl;
}



//////// その他共通関数定義 ////////
void my_new_handler() {
    std::cout << "Memory can't allocate." << std::endl;
    std::abort();
}