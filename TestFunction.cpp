#include <iostream>
#include <vector>
#include <new>
#include <climits>
#include "BasicClass.h"
#include "TestFunction.h"

using namespace std;


//////// private ////////
int TestFunction::foo(int a, int b) {return a + b;}
void TestFunction::foo(Ref& a) {a.num_ = a.num_ + 1;}
int TestFunction::ber(int a, int b) {return a - b;}

void TestFunction::FuncArgvBase(Base b) {
    b.FuncWithVirtual();
    b.FuncWithoutVirtual();
};
void TestFunction::FuncArgvSub(Sub s) {
    s.FuncWithVirtual();
    s.FuncWithoutVirtual();
};
void TestFunction::FuncArgvSub2(Sub2 s2) {
    s2.FuncWithVirtual();
    s2.FuncWithoutVirtual();
};
void TestFunction::FuncArgvBasePtr(Base* b) {
    b->FuncWithVirtual();
    b->FuncWithoutVirtual();
};
void TestFunction::FuncArgvSubPtr(Sub* s) {
    s->FuncWithVirtual();
    s->FuncWithoutVirtual();
};
void TestFunction::FuncArgvSub2Ptr(Sub2* s2) {
    s2->FuncWithVirtual();
    s2->FuncWithoutVirtual();
};
void TestFunction::FuncArgvBaseRef(Base& b) {
    b.FuncWithVirtual();
    b.FuncWithoutVirtual();
};
void TestFunction::FuncArgvSubRef(Sub& s) {
    s.FuncWithVirtual();
    s.FuncWithoutVirtual();
};
void TestFunction::FuncArgvSub2Ref(Sub2& s2) {
    s2.FuncWithVirtual();
    s2.FuncWithoutVirtual();
};


//////// public ////////
void TestFunction::CheckConstractorAndDestractor() {
    cout << endl;
    cout << "-------- Base class object generated. --------" << endl;

    Base obj_b;

    cout << endl;
    cout << "-------- Sub class object generated. --------" << endl;

    Sub  obj_s;

    cout << endl;
}


void TestFunction::CheckObjectSubstitution() {
    cout << endl;
    cout << "-------- Object substitution --------" << endl;

    Base obj_b1(1);
    Base obj_b2(2);

    obj_b1.GetInt();
    obj_b2.GetInt();

    obj_b2 = obj_b1;
    obj_b2.GetInt();

    cout << endl;
}


void TestFunction::CheckTypeInfo() {
    cout << endl;
    cout << "-------- Check type_info --------" << endl;

    const std::type_info& t1 = typeid(int);
    const std::type_info* t2 = &typeid(int);

    cout << "type = " << t1.name() << endl;
    cout << "type = " << t2->name() << endl;
    cout << "type = " << typeid(float).name() << endl;
    cout << "type = " << typeid(1 + 1.5).name() << endl;

    const std::type_info* ptr ;
    ptr = &typeid(int) ;
    ptr->name() ; // OK、

    class hoge {};
    hoge d;
    cout << (typeid(d) == typeid(hoge)) << endl;
    
    cout << endl;
}


void TestFunction::CheckDecltype() {
    cout << endl;
    cout << "-------- Check decltype --------" << endl;

    int i = 0;
    decltype(i) j = 1;      // j は int 型
    decltype(i)* p = &i;    // p は int 型のポインタ
    decltype((i)) k = i;    // k は int 型の参照(変数名 i の周りの余分な丸括弧に注意)

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    cout << "p = " << p << endl;
    cout << "k = " << k << endl;

    cout << endl;
}


void TestFunction::CheckNumOfArrayElement() {
    cout << endl;
    cout << "-------- Check number of array element --------" << endl;

    cout << "0th element count = " << std::extent<int[3][2], 0>::value << endl;
    cout << "1th element count = " << std::extent<int[3][2], 1>::value << endl;
    
    int Array[2][3] = {{1,2,3}, {4,5,6}};
    cout << "1th element count = "   << std::extent<decltype(Array), 1>::value << endl;

    cout << "int isn't array type: " << std::extent<int>::value                << endl;

    cout << endl;
}


void TestFunction::CheckObjectArray() {
    cout << endl;
    cout << "-------- Object array generation --------" << endl;

    Base obj_b[] = {Base(1, 2.3), Base(4, 5.6), Base(7, 8.3)};
    Base obj_c[] = {9, 8, 7};    // コンストラクタを省略できるのは、引数が1つのときだけ

    int num = std::extent<decltype(obj_b), 0>::value;
    for (int i; i<num; i++) {
        obj_b[i].Plus();
        obj_c[i].GetInt();
    }

    cout << endl;
}


void TestFunction::CheckObjecPointer() {
    cout << endl;
    cout << "-------- Check object pointer --------" << endl;

    Base obj_a[] = {1, 2, 3};
    Base* obj_p;

    obj_p = obj_a;
    obj_p->GetInt();
    (obj_p+1)->GetInt();
    (obj_p+2)->GetInt();

    cout << endl;
}


void TestFunction::CheckNewAndDelete() {
    cout << endl;
    cout << "-------- Check new and delete operater --------" << endl;

    // 未初期化
    Base* obj_p = new Base;
    int* i_p    = new int;
    obj_p->GetInt();
    cout << "int = " << *i_p << endl;

    // 初期化あり
    cout << endl;
    Base* obj_p2 = new Base(1);
    int* i_p2    = new int(5);
    obj_p2->GetInt();
    cout << "int2 = " << *i_p2 << endl;

    // 配列
    Base* obj_p3 = new Base[3];
    int* i_p3    = new int[3];
    for (int i=0; i<3; i++) {
        obj_p3->GetInt();
        cout << "int3 = " << *i_p3 << endl;
    }

    delete obj_p;
    delete i_p;
    delete obj_p2;
    delete i_p2;
    delete[] obj_p3;
    delete[] i_p3;

    // deleteはメモリの解放であって、宣言した変数の削除ではない。
    // i_p = new double;

    cout << endl;
}


void TestFunction::CheckNewHandler() {
    cout << endl;
    cout << "-------- Check new handler --------" << endl;

    std::set_new_handler(my_new_handler);


    int* p = new int[10000000000000000];
    delete[] p;

    cout << endl;
}


void TestFunction::CheckOperatorNewAndDelete() {
    cout << endl;
    cout << "-------- Check operator new and delete  --------" << endl;

    //////// 例外ありのoperator new/delete ////////
    void* tmp_p = operator new(sizeof(int)*10);    // new int[10]に相当
    int* p = reinterpret_cast<int*>(tmp_p);        // void*をint*に強制キャスト
    for (int i=0; i<10; i++) {
        p[i] = i;
        cout << p[i] << " ";
    }
    cout << endl;
    cout << "tmp_p address: " << tmp_p << endl;
    cout << "p     address: " << p << endl;
    operator delete(p);

    // メモリ解放後なので、ゴミデータが表示される
    for (int i=0; i<10; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    cout << endl;


    // //////// 例外なしのoperator new/delete ////////
    // //// MinGW環境だと使用できない？
    // Base* p2 = new(std::nothrow) Base[INT_MAX];
    // if (p2 == nullptr) {
    //     std::cout << "NULL pointer" << std::endl;
    // }
    // delete p2;
    // cout << endl;


    // //////// placement new ////////
    // //// MinGW環境だと使用できない？
    // //// 既存変数に新たなオブジェクトを生成する方法 ////
    // Base p3(1);
    // p3.GetInt();

    // // デストラクタを呼び出してオブジェクトを削除する(メモリ解放は行わない)
    // p3.~Base();

    // // 確保済みの変数の場所に、新たにオブジェクトを生成する。
    // // p3は、元々スコープを抜けると解放されるので、明示的にデストラクタを呼んではいけない。
    // Base* p4 = new(&p3) Base(2);
    // p3.GetInt();
    // p4->GetInt();
    // cout << "p3 address: " << &p3 << endl;
    // cout << "p4 address: " << p4 << endl;
    // cout << endl;

    // //// 静的メモリを確保しておいて後からコンストラクタを呼ぶ使い方 ////
    // char buf[sizeof(Base)];    // char型(1byte)でBase型分の配列(連続したメモリ領域)を確保
    // Base* p5 = new(buf) Base(3);
    // p5->GetInt();

    // // メモリp5は静的配列として別途確保したものであるため、手動でデストラクタを呼び出す
    // p5->~Base();
    // cout << endl;

    // //// 動的メモリだけ確保しておいて後からコンストラクタを呼ぶ使い方 ////
    // void* tmp_p2 = operator new(sizeof(Base));
    // p5 = reinterpret_cast<Base*>(tmp_p2);    // void*をBase*に強制キャスト
    // Base* p6 = new(p5) Base(4);
    // p5->GetInt();
    // p6->GetInt();

    // // メモリp5はoperator new 関数で別途確保したものであるため、メモリ解放の前にデストラクタを呼び出す
    // p6->~Base();
    // operator delete(p6);


    cout << endl;
}


void TestFunction::CheckDynamicArrayOfObject() {
    cout << endl;
    cout << "-------- Check dynamic array of object --------" << endl;


    //////// 引数付きコンストラクタを用いたクラス型配列の動的確保1 ////////
    // vectorを使用
    std::vector<Base> obj_p1;
    obj_p1.reserve(3);    // 3個分のメモリを確保(初期化はしない)
    for (int i=0; i<3; i++) {
        obj_p1.emplace_back(i);
        obj_p1[i].GetInt();
    }
    std::vector<Base>().swap(obj_p1);    // ここでswapしなければ、本関数の終わりでオブジェクトが破棄される。
    cout << endl;


    //////// 引数付きコンストラクタを用いたクラス型配列の動的確保2 ////////
    // ポインタへのポインタを使用
    Base** obj_p2 = new Base*[3];
    for (int i=0; i<3; i++) {
        obj_p2[i] = new Base(i+3);
        obj_p2[i]->GetInt();
    }

    // この記述がないと、各要素のポインタが指すアドレスに作成したオブジェクトが破棄されない
    for (int i=0; i<3; i++) {
        delete obj_p2[i];
    }

    // 確保したメモリ領域を解放
    delete[] obj_p2;
    cout << endl;


    // //////// 引数付きコンストラクタを用いたクラス型配列の動的確保3 ////////
    // // placement new を使用
    // Base* obj_p3 = reinterpret_cast<Base*>(operator new(sizeof(Base) * 3));
    // for(int i = 0; i < 3; i++){
    //     new(obj_p3+i) Base(i+6);
    //     obj_p3[i].GetInt();
    // }

    // // この記述がないと、各要素のポインタが指すアドレスに作成したオブジェクトが破棄されない
    // for(int i=0; i<3; i++){
    //     obj_p3[i].~Base();
    // }

    // // 確保したメモリ領域を解放
    // operator delete(obj_p3);


    cout << endl;
}


void TestFunction::CheckCopyConstractor() {
    cout << endl;
    cout << "-------- Check copy constractor --------" << endl;

    struct A {
        A() {cout << "Class A generated." << endl;}
        A(const A&) {cout << "Class A copied." << endl;}    // コピーコンストラクタ
        ~A() {cout << "Class A deleted" << endl;}
    };
    auto Func = [](A a) { return a; };

    // 直接初期化でデフォルトコンストラクタの呼び出し
    A a1;
    cout << endl;

    // 直接初期化でコピーコンストラクタの呼び出し
    A a2(a1);
    cout << endl;

    // コピー初期化でデフォルトコンストラクタの呼び出し
    A a3 = A();
    cout << endl;

    // 直接初期化でコピーコンストラクタの呼び出し
    A a4 = a1;
    cout << endl;

    // 関数内での一時オブジェクトによるコピーコンストラクタの呼び出し
    // 関数からの戻り一時オブジェクトによるコピーコンストラクタの呼び出し
    Func(a1);
    cout << endl;

    // 関数内での一時オブジェクトによるデフォルトコンストラクタの呼び出し
    // 関数からの戻り一時オブジェクトによるコピーコンストラクタの呼び出し
    Func(A());
    cout << endl;
}


void TestFunction::CheckStaticMember() {
    cout << endl;
    cout << "-------- Check static member --------" << endl;

    Base obj1, obj2;

    Base::StaticBaseFunc();    // 一般的な呼び方
    obj1.StaticBaseFunc();     // 一般的な呼び方ではないが、文法的にはOK
    obj2.StaticBaseFunc();     // static変数は共有されているので、同じ値が呼び出される

    Base::s_base_int_ = 1;    // 一般的な呼び方
    Base::StaticBaseFunc();
    obj1.s_base_int_++;       // 一般的な呼び方ではないが、文法的にはOK
    Base::StaticBaseFunc();
    obj2.s_base_int_++;       // static変数は共有されているので、同じ変数に対する操作になる
    Base::StaticBaseFunc();

    cout << endl;
}


void TestFunction::CheckObjectReference() {
    cout << endl;
    cout << "-------- Object reference --------" << endl;

    int    i = 1;
    double j = 2.3;

    int& k = i;
    const int& m = 5;
    const int& n = foo(1, 2);
    // int& k = 0;        // const でない参照の初期化子に rvalue は使用できない
    // int& k = foo();    // const でない参照の初期化子に rvalue は使用できない
    // int& k = j;        // 型が異なるのでエラー

    cout << "i = " << i << endl;
    cout << "k = " << k << endl;

    k = j;
    cout << "i = " << i << endl;
    cout << "k = " << k << endl;

    cout << "m = " << m << endl;
    cout << "n = " << n << endl;

    //////// 配列の参照 ////////
    cout << endl;
    int Array[] = {1,2,3,4,5};
    int (&refA)[5] = Array;
    cout << "Array[3] = " << Array[3] << endl;
    cout << "refA[3]  = " << refA[3] << endl;
    refA[3] = 0;
    cout << "Array[3] = " << Array[3] << endl;
    cout << "refA[3]  = " << refA[3] << endl;


    //////// 関数への参照 ////////
    cout << endl;
    // グローバル空間に定義したberはOKだが、クラスのメンバ関数にするとNG
    // static メンバ関数にすればOK
    int (&ber_ref)(int, int) = ber;
    cout << "ber     = " << ber(5, 1) << endl;
    cout << "ber_ref = " << ber_ref(5, 1) << endl;

    cout << endl;
}


void TestFunction::CheckObjectReference2() {
    cout << endl;
    cout << "-------- Object reference2 --------" << endl;

    //////// 参照渡し ////////
    cout << endl;
    Ref obj;
    obj.num_ = 1;
    std::cout << "num_ = " << obj.num_ << std::endl;
    foo(obj);    // オブジェクトをそのまま渡す
    std::cout << "num_ = " << obj.num_ << std::endl;


    //////// 参照返し ////////
    cout << "num2_ = " << obj.GetRefNum() << endl;

    // 関数の戻り値が private なメンバ変数の参照であるため、代入操作ができる。
    obj.GetRefNum() = 20;

    cout << "num2_ = " << obj.GetRefNum() << endl;
    cout << endl;
}


void TestFunction::CheckInheritance() {
    cout << "-------- Check object inheritance --------" << endl;
    cout << endl;

    class A {
    public:
        A() {cout << "A" << endl;}
    };

    class B {
    public:
        B() {cout << "B" << endl;}
    };

    class C : public B, public A {
    public:
        int a_;
        int b_;

        // 初期化子リストに記載した順序は無視される
        // `B()`, `A()`, `a(1)`, `b(a + 1)`の順番で呼び出される
        // コンパイル時に、-Wall オプションを有効にすると、
        // 初期化リストの記載順と、実際の初期化順が合っていない場合はwarningがでる。
        // C() : b_(a_ + 1), a_(1) , A() , B() {
        C() : B(), A(), a_(1), b_(a_ + 1) {
            cout << "a = " << a_ << endl;
            cout << "b = " << b_ << endl;
        }
    };

    C obj;

    cout << endl;
}


void TestFunction::CheckInheritance2() {
    cout << "-------- Check object inheritance 2 --------" << endl;
    cout << endl;

    Sub sub;
    sub.PrintBaseMember();
    sub.PrintSubMember();

    cout << endl;
}


void TestFunction::CheckSubClassUpcast() {
    cout << "-------- Check sub class upcast --------" << endl;
    cout << endl;

    //////// 基底クラス型ポインタへのアップキャスト ////////
    //// ポインタへの代入
    Base* base1;
    Sub   sub1;
    sub1.BaseFunc();    // 派生クラスは基底クラスメンバも使える
    sub1.SubFunc();

    base1 = &sub1;           // 基底クラスのポインタへ代入
    base1->BaseFunc();       // 基底クラスメンバは使える
    // base1->SubFunc();     // 派生クラスメンバは使用できない

    //// 動的メモリで生成
    cout << endl;
    Base* base2 = new Sub;
    base2->BaseFunc();      // 基底クラスメンバは使える
    // base2->SubFunc();    // 派生クラスメンバは使用できない
    delete base2;


    //////// 基底クラス型参照へのアップキャスト ////////
    cout << endl;
    Sub sub3;
    Base& base3 = sub3;
    base3.BaseFunc();       // 基底クラスメンバは使える
    // base3.SubFunc();     // 派生クラスメンバは使用できない


    cout << endl;
}


void TestFunction::CheckHiding() {
    cout << "-------- Check hiding --------" << endl;
    cout << endl;

    Base base;
    Sub  sub;
    std::string str = "test";

    cout << endl;
    base.Print(1);
    // sub.Print(1);    // 隠蔽されているので使用できない
    sub.Print(str);

    cout << endl;
}


void TestFunction::CheckOverride() {
    cout << "-------- Check function override --------" << endl;
    cout << endl;

    Sub sub;
    cout << endl;

    //////// 値渡し ////////
    // スライシング発生
    // 値渡しでは、一時オブジェクトの生成・破棄も行われる
    cout << "---- Value ----" << endl;
    FuncArgvBase(sub);
    cout << endl;


    //////// ポインタ渡し ////////
    // ポインタ渡しの場合、仮想関数は派生クラスのものが呼び出される。
    cout << "---- Pointer ----" << endl;
    FuncArgvBasePtr(&sub);
    cout << endl;


    //////// 参照渡し ////////
    // 参照渡しの場合、仮想関数は派生クラスのものが呼び出される。
    cout << "---- Reference ----" << endl;
    FuncArgvBaseRef(sub);
    cout << endl;


    cout << endl;
}


void TestFunction::CheckObjectSlicing() {
    cout << "-------- Check object slicing --------" << endl;
    cout << endl;

    //////// オブジェクトへの代入 ////////
    Base base(100);
    Sub  sub(200);
    base = sub;    // スライシング発生

    // 基底クラスのメンバは普通に使用できる
    base.BaseFunc();
    cout << "public_base_int_ = " << base.public_base_int_ <<endl;

    // スライシングにより、派生クラスのメンバは使用できない
    // cout << "public_sub_int_ = " << base.public_sub_int_ <<endl;
    // base.SubFunc();

    // 呼び出している基底クラスのメンバは、baseオブジェクトのものではなく
    // **subオブジェクトが内包している基底クラスのメンバである**。
    base.GetInt();
    sub.GetInt();


    //////// 関数への代入 ////////
    // 仮想関数でも基底クラスのものが呼び出される。
    cout << endl;
    FuncArgvBase(sub);

    cout << endl;
}


void TestFunction::CheckMultiInheritance() {
    cout << endl;
    cout << "-------- Check multi inheritance --------" << endl;

    class Base {
    protected:
        int base_int_ = 1;
    public:
        Base(void) {cout << "Base class generated." << endl;}
        virtual ~Base(void) {cout << "Base class deleted." << endl;}
        void BaseFunc(void) {cout << "Function from Base class." << endl;}
        void virtual func() {cout << "Base" << endl;}
    };

    class Sub1 : public virtual Base {
    public:
        Sub1(void) {cout << "Sub1 class generated." << endl;}
        ~Sub1(void) {cout << "Sub1 class deleted." << endl;}
        void SubFunc(void) {cout << "Function from Sub1 class." << endl;}
        void GetIntFromSub1() {cout << "base_int_ = " << base_int_ << endl;}
        // void func() { cout << "Sub1" << endl; }
    };

    class Sub2 : public virtual Base {
    public:
        Sub2(void) {cout << "Sub2 class generated." << endl;}
        ~Sub2(void) {cout << "Sub2 class deleted." << endl;}
        void SubFunc(void) {cout << "Function from Sub2 class." << endl;}
        void GetIntFromSub2() {cout << "base_int_ = " << base_int_ << endl;}
        // void func() { cout << "Sub2" << endl; }
    };

    class Sub3 : public Sub1, public Sub2 {
    public:
        Sub3(void) {cout << "Sub3 class generated." << endl;}
        ~Sub3(void) {cout << "Sub3 class deleted." << endl;}
    };

    Sub3 obj;
    obj.BaseFunc();         // 仮想継承すればBaseクラスのメンバ関数を呼び出せるようになる
    // obj.SubFunc();       // 仮想継承しても、Sub1, Sub2で同名の関数は曖昧なまま
    obj.Sub2::SubFunc();    // スコープ解決演算子で、アクセス経路を指定すればOK


    cout << endl;
}


int& Ref::GetRefNum() {return num2_;}

