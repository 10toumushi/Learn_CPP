// #pragma once
#ifndef _BASIC_CLASS_H_
#define _BASIC_CLASS_H_


// 基底クラス
class Base {
private:
    int base_int_;
    double base_double_;
    std::string base_string_;
    int private_int_ = 0;

public:
    int public_base_int_ = 1;
    int public_int_ = 1;
    static int s_base_int_;
    Base(void);    // デフォルトコンストラクタ
    Base(int);
    Base(int, double);
    Base(const Base&);    // コピーコンストラクタ
    virtual ~ Base(void);
    // ~ Base(void);
    virtual void FuncWithVirtual(void);
    void FuncWithoutVirtual(void);
    void PrintBaseMember(void);
    void BaseFunc(void);
    void SetInt(int);
    virtual void GetInt(void);
    virtual void Plus(void);
    virtual void Print(int);
    static void StaticBaseFunc(void);
};


// 派生クラス
class Sub : public Base {
private:
    int sub_int_;
    double sub_double_;
    std::string sub_string_;
    int private_int_ = 2;

public:
    int public_sub_int_ = 3;
    int public_int_ = 3;
    static int s_sub_int_;
    Sub(void);
    Sub(int);
    Sub(int, double);
    ~ Sub(void);
    void FuncWithVirtual(void);
    void FuncWithoutVirtual(void);
    void PrintSubMember(void);
    void SubFunc(void);
    void SetInt(int);
    void GetInt(void);

    void Plus(void);
    void Print(std::string);
    static void StaticSubFunc(void);
};


// 派生クラス2
class Sub2 : public Sub {
private:
    int sub2_int_;
    double sub2_double_;
    std::string sub2_string_;
    int private_int_ = 4;

public:
    int public_sub2_int_ = 5;
    static int s_sub2_int_;
    Sub2(void);
    Sub2(int);
    Sub2(int, double);
    ~ Sub2(void);
    void FuncWithVirtual(void);
    void FuncWithoutVirtual(void);
    void PrintSub2Member(void);
    void Sub2Func(void);
    void SetInt(int);
    void GetInt(void);
    void Plus(void);
    void Print(double);
    static void StaticSub2Func(void);
};


void my_new_handler();

#endif // _BASIC_CLASS_H_