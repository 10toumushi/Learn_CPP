#include <iostream>
#include <vector>
#include <new>
#include "BasicClass.h"
#include "TestFunction.h"
using namespace std;
#include <climits>

void g(Base* b) {
    b->f();
}


void g(Sub* s) {
    s->f();
}

void g(Base b) {
    b.f();
}

// void g(Sub s) {
//     s.f();
// }

int TestFunction::foo(int a, int b) {return a + b;}
int TestFunction::ber(int a, int b) {return a - b;}
void TestFunction::foo(Ref& a) {a.num_ = a.num_ + 1;}


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


    //////// 引数付きコンストラクタを用いたクラス型配列の動的確保3 ////////
    // placement new を使用
    Base* obj_p3 = reinterpret_cast<Base*>(operator new(sizeof(Base) * 3));
    for(int i = 0; i < 3; i++){
        new(obj_p3+i) Base(i+6);
        obj_p3[i].GetInt();
    }

    // この記述がないと、各要素のポインタが指すアドレスに作成したオブジェクトが破棄されない
    for(int i=0; i<3; i++){
        obj_p3[i].~Base();
    }

    // 確保したメモリ領域を解放
    operator delete(obj_p3);


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

    // 配列の参照
    cout << endl;
    int Array[] = {1,2,3,4,5};
    int (&refA)[5] = Array;
    cout << "Array[3] = " << Array[3] << endl;
    cout << "refA[3]  = " << refA[3] << endl;
    refA[3] = 0;
    cout << "Array[3] = " << Array[3] << endl;
    cout << "refA[3]  = " << refA[3] << endl;

    // 関数への参照
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
    Ref a;
    a.num_ = 1;
    std::cout << "num_ = " << a.num_ << std::endl;
    foo(a);    // オブジェクトをそのまま渡す
    std::cout << "num_ = " << a.num_ << std::endl;

    //////// 参照返し ////////
    cout << "num2_ = " << a.GetRefNum() << endl;

    // 関数の戻り値が private なメンバ変数の参照であるため、代入操作ができる。
    a.GetRefNum() = 20;

    cout << "num2_ = " << a.GetRefNum() << endl;
    cout << endl;
}


int& Ref::GetRefNum() {return num2_;}

