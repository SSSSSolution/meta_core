#ifndef _META_CORE_CLASS_INFO_H_
#define _META_CORE_CLASS_INFO_H_

#include "class_info_macro.h"
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <assert.h>

#include "template_tool.h"


#define META_DECLARE_CLASS META_CORE_CLASS_INFO_DECLARE_CLASS

#define META_REG_CLASS(class_name, space_class_name) META_CORE_CLASS_INFO_REGISTER_CLASS(class_name, space_class_name)

// declare and register string
#define META_DECLARE_RW_STR(prop_name) META_CORE_CLASS_INFO_DECLARE_RW_STR_PROP(prop_name)
#define META_DECLARE_R_STR(prop_name)  META_CORE_CLASS_INFO_DECLARE_R_STR_PROP(prop_name)
#define META_DECLARE_W_STR(prop_name)  META_CORE_CLASS_INFO_DECLARE_W_STR_PROP(prop_name)

#define META_REG_RW_STR(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_RW_STR_PROP(class_name, prop_name)
#define META_REG_R_STR(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_R_STR_PROP(class_name, prop_name)
#define META_REG_W_STR(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_W_STR_PROP(class_name, prop_name)

// declare and register real
#define META_DECLARE_RW_REAL(prop_name) META_CORE_CLASS_INFO_DECLARE_RW_REAL_PROP(prop_name)
#define META_DECLARE_R_REAL(prop_name)  META_CORE_CLASS_INFO_DECLARE_R_REAL_PROP(prop_name)
#define META_DECLARE_W_REAL(prop_name)  META_CORE_CLASS_INFO_DECLARE_W_REAL_PROP(prop_name)

#define META_REG_RW_REAL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_RW_REAL_PROP(class_name, prop_name)
#define META_REG_R_REAL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_R_REAL_PROP(class_name, prop_name)
#define META_REG_W_REAL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_W_REAL_PROP(class_name, prop_name)

// declare and register bool
#define META_DECLARE_RW_BOOL(prop_name) META_CORE_CLASS_INFO_DECLARE_RW_BOOL_PROP(prop_name)
#define META_DECLARE_R_BOOL(prop_name)  META_CORE_CLASS_INFO_DECLARE_R_BOOL_PROP(prop_name)
#define META_DECLARE_W_BOOL(prop_name)  META_CORE_CLASS_INFO_DECLARE_W_BOOL_PROP(prop_name)

#define META_REG_RW_BOOL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_RW_BOOL_PROP(class_name, prop_name)
#define META_REG_R_BOOL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_R_BOOL_PROP(class_name, prop_name)
#define META_REG_W_BOOL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_W_BOOL_PROP(class_name, prop_name)

// declare and register obj
#define META_DECLARE_RW_OBJ(prop_name, T) META_CORE_CLASS_INFO_DECLARE_RW_OBJ_PROP(prop_name, T)
#define META_DECLARE_R_OBJ(prop_name, T)  META_CORE_CLASS_INFO_DECLARE_R_OBJ_PROP(prop_name, T)
#define META_DECLARE_W_OBJ(prop_name, T)  META_CORE_CLASS_INFO_DECLARE_W_OBJ_PROP(prop_name, T)

#define META_REG_RW_OBJ(class_name, prop_name, T) META_CORE_CLASS_INFO_REGISTER_RW_OBJ_PROP(class_name, prop_name, T)
#define META_REG_R_OBJ(class_name, prop_name, T) META_CORE_CLASS_INFO_REGISTER_R_OBJ_PROP(class_name, prop_name, T)
#define META_REG_W_OBJ(class_name, prop_name, T) META_CORE_CLASS_INFO_REGISTER_W_OBJ_PROP(class_name, prop_name, T)

// declare and register vec string
#define META_DECLARE_RW_VEC_STR(prop_name) META_CORE_CLASS_INFO_DECLARE_RW_VEC_STR_PROP(prop_name)
#define META_DECLARE_R_VEC_STR(prop_name)  META_CORE_CLASS_INFO_DECLARE_R_VEC_STR_PROP(prop_name)
#define META_DECLARE_W_VEC_STR(prop_name)  META_CORE_CLASS_INFO_DECLARE_W_VEC_STR_PROP(prop_name)

#define META_REG_RW_VEC_STR(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_RW_VEC_STR_PROP(class_name, prop_name)
#define META_REG_R_VEC_STR(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_R_VEC_STR_PROP(class_name, prop_name)
#define META_REG_W_VEC_STR(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_W_VEC_STR_PROP(class_name, prop_name)

// declare and register vec real
#define META_DECLARE_RW_VEC_REAL(prop_name) META_CORE_CLASS_INFO_DECLARE_RW_VEC_REAL_PROP(prop_name)
#define META_DECLARE_R_VEC_REAL(prop_name)  META_CORE_CLASS_INFO_DECLARE_R_VEC_REAL_PROP(prop_name)
#define META_DECLARE_W_VEC_REAL(prop_name)  META_CORE_CLASS_INFO_DECLARE_W_VEC_REAL_PROP(prop_name)

#define META_REG_RW_VEC_REAL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_RW_VEC_REAL_PROP(class_name, prop_name)
#define META_REG_R_VEC_REAL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_R_VEC_REAL_PROP(class_name, prop_name)
#define META_REG_W_VEC_REAL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_W_VEC_REAL_PROP(class_name, prop_name)

// declare and register vec bool
#define META_DECLARE_RW_VEC_BOOL(prop_name) META_CORE_CLASS_INFO_DECLARE_RW_VEC_BOOL_PROP(prop_name)
#define META_DECLARE_R_VEC_BOOL(prop_name)  META_CORE_CLASS_INFO_DECLARE_R_VEC_BOOL_PROP(prop_name)
#define META_DECLARE_W_VEC_BOOL(prop_name)  META_CORE_CLASS_INFO_DECLARE_W_VEC_BOOL_PROP(prop_name)

#define META_REG_RW_VEC_BOOL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_RW_VEC_BOOL_PROP(class_name, prop_name)
#define META_REG_R_VEC_BOOL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_R_VEC_BOOL_PROP(class_name, prop_name)
#define META_REG_W_VEC_BOOL(class_name, prop_name) META_CORE_CLASS_INFO_REGISTER_W_VEC_BOOL_PROP(class_name, prop_name)

// declare and register vec bool
#define META_DECLARE_RW_VEC_OBJ(prop_name, T) META_CORE_CLASS_INFO_DECLARE_RW_VEC_OBJ_PROP(prop_name, T)
#define META_DECLARE_R_VEC_OBJ(prop_name, T)  META_CORE_CLASS_INFO_DECLARE_R_VEC_OBJ_PROP(prop_name, T)
#define META_DECLARE_W_VEC_OBJ(prop_name, T)  META_CORE_CLASS_INFO_DECLARE_W_VEC_OBJ_PROP(prop_name, T)

#define META_REG_RW_VEC_OBJ(class_name, prop_name, T) META_CORE_CLASS_INFO_REGISTER_RW_VEC_OBJ_PROP(class_name, prop_name, T)
#define META_REG_R_VEC_OBJ(class_name, prop_name, T) META_CORE_CLASS_INFO_REGISTER_R_VEC_OBJ_PROP(class_name, prop_name, T)
#define META_REG_W_VEC_OBJ(class_name, prop_name, T) META_CORE_CLASS_INFO_REGISTER_W_VEC_OBJ_PROP(class_name, prop_name, T)

namespace meta_core
{

enum PropType
{
    Invalid = 0,

    String,
    Real,
    Bool,
    Object,

    Vector_str,
    Vector_real,
    Vector_bool,
    Vector_Object,
};

enum PropAccessPermission
{
    ReadWrite,
    ReadOnly,
    WriteOnly,
};

class ClassInfo;

typedef ClassInfo *class_create_func_t();

// for register class
struct PropRecordBase
{
    virtual ~PropRecordBase() {}
    PropType type;
    PropAccessPermission access_permission;
};

template <typename T>
struct PropRecord: public PropRecordBase
{
    std::function<void (ClassInfo *, const T&)> set_func;
    std::function<const T&(ClassInfo *)> get_func;
};

struct ClassRecord
{
    std::string class_name;
    std::function<class_create_func_t> class_create_func;
    std::map<std::string, std::shared_ptr<PropRecordBase> > props_map;
};


// prop value
class PropValueBase
{
public:
    virtual ~PropValueBase() {}
    PropType type = Invalid;
};

template <typename T>
class PropValue : public PropValueBase
{
public:
    T value;

};

template<>
class PropValue <std::string> : public PropValueBase
{
public:
    PropValue()
    {
        type = String;
    }
    std::string value;
};

template<>
class PropValue <double> : public PropValueBase
{
public:
    PropValue()
    {
        type = Real;
    }
    double value;
};

template<>
class PropValue <bool> : public PropValueBase
{
public:
    PropValue()
    {
        type = Bool;
    }
    bool value;
};

template<typename T>
class PropValue <std::shared_ptr<T>> : public PropValueBase
{
public:
    PropValue()
    {
        if (std::is_base_of<ClassInfo, T>::value)
        {
            type = Object;
        }
    }
    std::shared_ptr<T> value;
};

template<>
class PropValue <std::vector<std::string>> : public PropValueBase
{
public:
    PropValue()
    {
        type = Vector_str;
    }
    std::vector<std::string> value;
};

template<>
class PropValue <std::vector<double>> : public PropValueBase
{
public:
    PropValue()
    {
        type = Vector_real;
    }
    std::vector<double> value;
};

template<>
class PropValue <std::vector<bool>> : public PropValueBase
{
public:
    PropValue()
    {
        type = Vector_bool;
    }
    std::vector<bool> value;
};

template<typename T>
class PropValue <std::vector<std::shared_ptr<T>>> : public PropValueBase
{
public:
    PropValue()
    {
        if (std::is_base_of<ClassInfo, T>::value)
        {
            type = Vector_Object;
        }
    }
    std::vector<std::shared_ptr<T>> value;
};



extern std::map<std::string, std::shared_ptr<ClassRecord> > g_class_records_map;
class ClassInfo
{
public:
    virtual ~ClassInfo() {}
    static bool register_class(const std::string &class_name,
                               std::function<class_create_func_t> create_func);
    static ClassInfo *create_class(const std::string &class_name);

    template<typename T>
    static bool register_prop(const std::string &class_name,
                              const std::string &prop_name,
                              PropAccessPermission ap,
                              std::function<void (ClassInfo *, const T&)> set_func,
                              std::function<const T&(ClassInfo *)> get_func)
    {
        if (g_class_records_map.count(class_name) == 0)
        {
            std::cout << "Prop <" << prop_name << "> reigster failed: class<" << class_name << "> has not been registered." << std::endl;
            return false;
        }
        auto class_record = g_class_records_map[class_name];

        if (class_record->props_map.count(prop_name) > 0)
        {
            std::cout << "Prop <" << prop_name << "> reigster failed: prop<" << prop_name << "> has already been registered." << std::endl;
            return false;
        }

        // check func
        switch (ap)
        {
        case ReadWrite:
            if (!set_func || !get_func)
            {
                std::cout << "Both READWRITE Prop's set_func and get_func must not be empty" << std::endl;
                return false;
            }
            break;
        case ReadOnly:
            if (!get_func)
            {
                std::cout << "The get func of ReadOnly prop cannot be empty." << std::endl;
                return false;
            }
            break;
        case WriteOnly:
            if (!set_func)
            {
                std::cout << "The set func of WriteOnly prop cannot be empty." << std::endl;
                return false;
            }
            break;
        }

        auto prop_record = std::make_shared<PropRecord<T>>();
        if (std::is_same<T, std::string>::value)
        {
            prop_record->type = String;
        }
        else if (std::is_same<T, double>::value)
        {
            prop_record->type = Real;
        }
        else if (std::is_same<T, bool>::value)
        {
            prop_record->type = Bool;
        }
        else if (meta_core::is_base_of_smart_ptr_inside_type<ClassInfo, T>::value)
        {
            prop_record->type = Object;
        }
        // vector type
        else if (std::is_same<T, std::vector<std::string>>::value)
        {
            prop_record->type = Vector_str;
        }
        else if (std::is_same<T, std::vector<double>>::value)
        {
            prop_record->type = Vector_real;
        }
        else if (std::is_same<T, std::vector<bool>>::value)
        {
            prop_record->type = Vector_bool;
        }
        else if (meta_core::is_base_of_smart_ptr_vec_inside_type<ClassInfo, T>::value)
        {
            prop_record->type = Vector_Object;
        }
        // register failed
        else
        {
            std::cout << "register prop: " << class_name << "." << prop_name << " failed." << std::endl;
            return false;
        }

        prop_record->access_permission = ap;
        prop_record->set_func = set_func;
        prop_record->get_func = get_func;
        class_record->props_map[prop_name] = prop_record;
        std::cout << "register prop: " << class_name << "." << prop_name << " success." << std::endl;
        return true;
    }

    static std::shared_ptr<PropValueBase> get_prop(ClassInfo *pClass, const std::string &prop_name);

    template <typename T>
    static bool set_prop(ClassInfo *pClass, const std::string &prop_name, const std::shared_ptr<PropValue<T>> &value)
    {
        if (g_class_records_map.count(pClass->get_class_name()) == 0)
        {
            std::cout << "Error: class is not reigistered" << std::endl;
            return false;
        }

        auto classRecord = g_class_records_map[pClass->get_class_name()];
        if (classRecord->props_map.count(prop_name) == 0)
        {
            std::cout << "Error: prop is not exist" << std::endl;
            return false;
        }

        std::shared_ptr<PropRecordBase> propRecord = classRecord->props_map[prop_name];
        if (propRecord->access_permission == ReadOnly)
        {
            std::cout << "Error: prop is read only!" << std::endl;
            return false;
        }

        if (value->type == PropType::Invalid)
        {
            return false;
        }

        auto tmpPropRecord = static_cast<PropRecord<T> *>(propRecord.get());
        tmpPropRecord->set_func(pClass, value->value);
        return true;
    }

    virtual const std::string &get_class_name() = 0;
};



}

#endif

