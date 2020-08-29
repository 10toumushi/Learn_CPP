// #pragma once
#ifndef _BASIC_CLASS_H_
#define _BASIC_CLASS_H_


// 基底クラス
class Base {
private:
    int base_int_;
    double base_double_;
    std::string base_string_;
    int num_int_ = 0;

public:
    static int s_base_int_;
    Base(void);
    Base(int);
    Base(int, double);
    virtual ~ Base(void);
    // void f(void);
    virtual void f(void);

    void PrintBaseMember(void);

    void BaseFunc(void);
    void SetInt(int);
    virtual void GetInt(void);
    virtual void Plus(void);
    virtual void PrintString(std::string);
    static void StaticBaseFunc(void);
};


// 派生クラス
class Sub : public Base {
private:
    int sub_int_;
    double sub_double_;
    std::string sub_string_;
    int num_int_ = 1;

public:
    static int s_sub_int_;
    Sub(void);
    Sub(int);
    Sub(int, double);
    ~ Sub(void);

    void f(void);
    // void f(void) override;

    void PrintSubMember(void);

    void SubFunc(void);
    void SetInt(int);
    void GetInt(void);
    void Plus(void);
    void PrintString(std::string);
    static void StaticSubFunc(void);
};


void my_new_handler();

#endif // _BASIC_CLASS_H_