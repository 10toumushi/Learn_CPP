#include <bits/stdc++.h>
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

Base::~Base(void) {
    cout << "Base class deleted." << endl;
}

void Base::f(void) {
    cout << "Func from Base class." << endl;
}

void Base::PrintBaseMember(void) {
    cout << "Base member = " << num_int_ << endl;
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

void Base::PrintString(std::string str) {
    cout << str << endl;
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

void Sub::f(void) {
    cout << "Func from Sub class." << endl;
}

void Sub::PrintSubMember(void) {
    cout << "Sub member = " << num_int_ << endl;
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

void Sub::PrintString(std::string str) {
    cout << str << endl;
}

int Sub::s_sub_int_ = 456;

void Sub::StaticSubFunc(void) {
    cout << "s_sub_int_ = " << s_sub_int_ << endl;
}


void my_new_handler() {
    std::cout << "Memory can't allocate." << std::endl;
    std::abort();
}