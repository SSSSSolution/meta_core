#include "class_info.h"
#include <iostream>
#include <assert.h>

using namespace meta_core;

class TestB;
namespace ns_a {

class None
{

};

class TestA : public meta_core::ClassInfo
{
    META_DECLARE_CLASS
public:
    TestA()
        : m_rwa("m_rwa"),
          m_ra("m_ra"),
          m_wa("m_wa")
    {
        // real
        m_rw_real = 1.0;
        m_r_real = 2.0;
        m_w_real = 3.0;

        // bool
        m_rw_bool = true;
        m_r_bool = false;
        m_w_bool = true;

        // obj
        m_rw_obj = std::make_shared<TestB>(1);
        m_r_obj = std::make_shared<TestB>(2);
        m_w_obj = std::make_shared<TestB>(3);

        // vec str
        m_rw_vec_str.push_back("1");
        m_rw_vec_str.push_back("2");
        m_rw_vec_str.push_back("3");
        m_rw_vec_str.push_back("4");

        // vec real
        m_rw_vec_real.push_back(1.23);
        m_rw_vec_real.push_back(3.45);
        m_rw_vec_real.push_back(5.67);
        m_rw_vec_real.push_back(7.89);

        // vec bool
        m_rw_vec_bool.push_back(false);
        m_rw_vec_bool.push_back(true);
        m_rw_vec_bool.push_back(false);
        m_rw_vec_bool.push_back(true);

        // vec obj
        m_rw_vec_obj.push_back(std::make_shared<TestB>(1));
        m_rw_vec_obj.push_back(std::make_shared<TestB>(2));
        m_rw_vec_obj.push_back(std::make_shared<TestB>(3));
        m_rw_vec_obj.push_back(std::make_shared<TestB>(4));
        m_rw_vec_obj.push_back(std::make_shared<TestB>(5));
    }

    META_DECLARE_RW_STR(rwa)
    META_DECLARE_R_STR(ra)
    META_DECLARE_W_STR(wa)

    META_DECLARE_RW_REAL(rw_real)
    META_DECLARE_R_REAL(r_real)
    META_DECLARE_W_REAL(w_real)

    META_DECLARE_RW_BOOL(rw_bool)
    META_DECLARE_R_BOOL(r_bool)
    META_DECLARE_W_BOOL(w_bool)

    META_DECLARE_RW_OBJ(rw_obj, TestB)
    META_DECLARE_R_OBJ(r_obj, TestB)
    META_DECLARE_W_OBJ(w_obj, TestB)

    META_DECLARE_RW_VEC_STR(rw_vec_str)
    META_DECLARE_R_VEC_STR(r_vec_str)
    META_DECLARE_W_VEC_STR(w_vec_str)

    META_DECLARE_RW_VEC_REAL(rw_vec_real)
    META_DECLARE_R_VEC_REAL(r_vec_real)
    META_DECLARE_W_VEC_REAL(w_vec_real)

    META_DECLARE_RW_VEC_BOOL(rw_vec_bool)
    META_DECLARE_R_VEC_BOOL(r_vec_bool)
    META_DECLARE_W_VEC_BOOL(w_vec_bool)

    META_DECLARE_RW_VEC_OBJ(rw_vec_obj, TestB)
    META_DECLARE_R_VEC_OBJ(r_vec_obj, TestB)
    META_DECLARE_W_VEC_OBJ(w_vec_obj, TestB)

};

META_REG_CLASS(TestA, ns_a::TestA)
META_REG_RW_STR(TestA, rwa)
META_REG_R_STR(TestA, ra)
META_REG_W_STR(TestA, wa)

META_REG_RW_REAL(TestA, rw_real)
META_REG_R_REAL(TestA, r_real)
META_REG_W_REAL(TestA, w_real)

META_REG_RW_BOOL(TestA, rw_bool)
META_REG_R_BOOL(TestA, r_bool)
META_REG_W_BOOL(TestA, w_bool)

META_REG_RW_OBJ(TestA, rw_obj, TestB)
META_REG_R_OBJ(TestA, r_obj, TestB)
META_REG_W_OBJ(TestA, w_obj, TestB)

META_REG_RW_VEC_STR(TestA, rw_vec_str)
META_REG_R_VEC_STR(TestA, r_vec_str)
META_REG_W_VEC_STR(TestA, w_vec_str)

META_REG_RW_VEC_REAL(TestA, rw_vec_real)
META_REG_R_VEC_REAL(TestA, r_vec_real)
META_REG_W_VEC_REAL(TestA, w_vec_real)

META_REG_RW_VEC_BOOL(TestA, rw_vec_bool)
META_REG_R_VEC_BOOL(TestA, r_vec_bool)
META_REG_W_VEC_BOOL(TestA, w_vec_bool)

META_REG_RW_VEC_OBJ(TestA, rw_vec_obj, TestB)
META_REG_R_VEC_OBJ(TestA, r_vec_obj, TestB)
META_REG_W_VEC_OBJ(TestA, w_vec_obj, TestB)

}

class TestB : public meta_core::ClassInfo
{
    META_DECLARE_CLASS
public:
    TestB()
    {}

    TestB(int id)
    {
        m_id = id;
        std::cout << "create Test B" << std::endl;
    }

    int m_id = 0;

     META_DECLARE_RW_STR(rwa)
     META_DECLARE_R_STR(ra)
     META_DECLARE_W_STR(wa)

     META_DECLARE_RW_REAL(rw_real)
     META_DECLARE_R_REAL(r_real)
     META_DECLARE_W_REAL(w_real)

//     META_DECLARE_RW_

};

META_REG_CLASS(TestB, ::TestB)
META_REG_RW_STR(TestB, rwa)
META_REG_R_STR(TestB, ra)
META_REG_W_STR(TestB, wa)

META_REG_RW_REAL(TestB, rw_real)
META_REG_R_REAL(TestB, r_real)
META_REG_W_REAL(TestB, w_real)



static void printProp(ClassInfo *pClass, std::string prop_name)
{
    std::cout << pClass->get_class_name() << "'s prop " << prop_name << ": ";

    PropValue<std::string> *strValue;
    PropValue<double> *realValue;
    PropValue<bool> *boolValue;
    PropValue<std::shared_ptr<ClassInfo>> *objValue;
    PropValue<std::vector<std::string>> *vecStrValue;
    PropValue<std::vector<double>> *vecRealValue;
    PropValue<std::vector<bool>> *vecBoolValue;
    PropValue<std::vector<std::shared_ptr<ClassInfo>>> *vecObjValue;

    std::shared_ptr<PropValueBase> propValueBase = ClassInfo::get_prop(pClass, prop_name);
    switch (propValueBase->type)
    {
    case PropType::Invalid:
        std::cout << "invalid!!!" << std::endl;
        break;

    case PropType::String:
        strValue = static_cast<PropValue<std::string> *>(propValueBase.get());
        std::cout << "string[" << strValue->value << "]" << std::endl;
        break;
    case PropType::Real:
        realValue = static_cast<PropValue<double> *>(propValueBase.get());
        std::cout << "double[" << realValue->value << "]" << std::endl;
        break;
    case PropType::Bool:
        boolValue = static_cast<PropValue<bool> *>(propValueBase.get());
        std::cout << "bool[" << boolValue->value << "]" << std::endl;
        break;
    case PropType::Object:
        objValue = static_cast<PropValue<std::shared_ptr<ClassInfo>> *>(propValueBase.get());
        std::cout << "obj[" << objValue->value->get_class_name() << "]" << std::endl;
        break;

    case PropType::Vector_str:
        vecStrValue = static_cast<PropValue<std::vector<std::string>> *>(propValueBase.get());
        std::cout << "vecStr[";
        for (auto str : vecStrValue->value)
        {
            std::cout << str << " ";
        }
        std::cout << "]" << std::endl;
        break;
    case PropType::Vector_real:
        vecRealValue = static_cast<PropValue<std::vector<double>> *>(propValueBase.get());
        std::cout << "vecReal[";
        for (auto real : vecRealValue->value)
        {
            std::cout << real << " ";
        }
        std::cout << "]" << std::endl;
        break;
    case PropType::Vector_bool:
        vecBoolValue = static_cast<PropValue<std::vector<bool>> *>(propValueBase.get());
        std::cout << "vecBool[";
        for (auto b : vecBoolValue->value)
        {
            std::cout << b << " ";
        }
        std::cout << "]" << std::endl;
        break;
    case PropType::Vector_Object:
        vecObjValue = static_cast<PropValue<std::vector<std::shared_ptr<ClassInfo>>> *>(propValueBase.get());
        std::cout << "vecObj[";
        for (auto obj : vecObjValue->value)
        {
            if (auto pTestB = dynamic_cast<TestB *>(obj.get()))
            {
                std::cout << pTestB->get_class_name() << " ";
            }
        }
        std::cout << "]" << std::endl;
        break;
    }
}

template <typename T>
static bool setProp(ClassInfo *pClass, std::string prop_name, T value)
{
    auto prop_value = std::make_shared<PropValue<T>>();
    prop_value->value = value;
    return ClassInfo::set_prop(pClass, prop_name, prop_value);
}

int main(int argc, char **argv)
{
    std::cout << TO_STR( META_DECLARE_RW_OBJ(rw_obj, TestB *)) << std::endl;
    auto a = meta_core::ClassInfo::create_class("ns_a::TestA");
    if (a)
    {
        std::cout << "create TestA succ" << std::endl;
    }
    else
    {
        std::cout << "create TestA failed" << std::endl;
    }

    auto A = dynamic_cast<ns_a::TestA *>(a);
    assert(A != nullptr);

    A->set_rwa("testA's str a");
    std::cout << A->get_rwa() << std::endl;

    A->set_wa("123");
    std::cout << "ra: " << A->get_ra() << std::endl;

    printProp(A, "rwa");
    printProp(A, "ra");
    printProp(A, "wa");
    assert(setProp(A, "rwa", std::string("12345")));
    assert(A->get_rwa() == "12345");

    printProp(A, "rw_real");
    printProp(A, "r_real");
    printProp(A, "w_real");
    assert(setProp(A, "rw_real", 3.1415));
    std::cout << A->get_rw_real() << std::endl;

    printProp(A, "rw_bool");
    printProp(A, "r_bool");
    printProp(A, "w_bool");
    bool b = A->get_rw_bool();
    assert(setProp(A, "rw_bool", !b));
    assert(A->get_rw_bool() == !b);

    printProp(A, "rw_obj");
    printProp(A, "r_obj");
    printProp(A, "w_obj");
    auto testB =  std::make_shared<TestB>(5);
    assert(setProp(A, "rw_obj", testB));
    assert(A->get_rw_obj()->m_id == 5);


    printProp(A, "rw_vec_str");
    printProp(A, "r_vec_str");
    printProp(A, "w_vec_str");

    printProp(A, "rw_vec_real");
    printProp(A, "r_vec_real");
    printProp(A, "w_vec_real");

    printProp(A, "rw_vec_bool");
    printProp(A, "r_vec_bool");
    printProp(A, "w_vec_bool");

    printProp(A, "rw_vec_obj");
    printProp(A, "r_vec_obj");
    printProp(A, "w_vec_obj");

    return 0;
}















