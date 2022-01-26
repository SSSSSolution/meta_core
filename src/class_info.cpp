#include "class_info.h"
#include <iostream>

namespace meta_core
{
std::map<std::string, std::shared_ptr<ClassRecord> > g_class_records_map;

bool ClassInfo::register_class(const std::string &class_name,
                              std::function<class_create_func_t> create_func)
{
    if (g_class_records_map.count(class_name) > 0)
    {
        std::cout << "Class register failed: class <" << class_name << "> has already been registered." << std::endl;
        return false;
    }

    auto class_record = std::make_shared<ClassRecord>();
    class_record->class_name = class_name;
    class_record->class_create_func = create_func;

    g_class_records_map[class_name] = class_record;

    std::cout << "Class <" << class_name << "> register succ." << std::endl;
    return true;
}

ClassInfo *ClassInfo::create_class(const std::string &class_name)
{
    if (g_class_records_map.count(class_name) > 0)
    {
        return g_class_records_map[class_name]->class_create_func();
    }

    std::cout << "Class create failed: <" << class_name << "> has not been register." << std::endl;
    return nullptr;
}

std::shared_ptr<PropValueBase> ClassInfo::get_prop(ClassInfo *pClass, const std::string &prop_name)
{
    auto propValue = std::make_shared<PropValueBase>();
    if (g_class_records_map.count(pClass->get_class_name()) == 0)
    {
        std::cout << "Error: class is not reigistered" << std::endl;
        return propValue;
    }

    auto classRecord = g_class_records_map[pClass->get_class_name()];
    if (classRecord->props_map.count(prop_name) == 0)
    {
        std::cout << "Error: prop is not exist" << std::endl;
        return propValue;
    }

    std::shared_ptr<PropRecordBase> propRecord = classRecord->props_map[prop_name];
    if (propRecord->access_permission == WriteOnly)
    {
        std::cout << "Error: prop is write only!" << std::endl;
        return propValue;
    }

    if (propRecord->type == PropType::String)
    {
        auto strPropRecord = static_cast<PropRecord<std::string> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<std::string>>();
        retPropValue->type = PropType::String;
        retPropValue->value = strPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    else if (propRecord->type == PropType::Real)
    {
        auto strPropRecord = static_cast<PropRecord<double> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<double>>();
        retPropValue->type = PropType::Real;
        retPropValue->value = strPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    else if (propRecord->type == PropType::Bool)
    {
        auto strPropRecord = static_cast<PropRecord<bool> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<bool>>();
        retPropValue->type = PropType::Bool;
        retPropValue->value = strPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    else if (propRecord->type == PropType::Object)
    {
        auto objPropRecord = static_cast<PropRecord<std::shared_ptr<ClassInfo>> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<std::shared_ptr<ClassInfo>>>();
        retPropValue->type = PropType::Object;
        retPropValue->value = objPropRecord->get_func(pClass);
        std::shared_ptr<ClassInfo> testobj = objPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    // vector type
    else if (propRecord->type == PropType::Vector_str)
    {
        auto vecStrPropRecord = static_cast<PropRecord<std::vector<std::string>> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<std::vector<std::string>>>();
        retPropValue->type = PropType::Vector_str;
        retPropValue->value = vecStrPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    else if (propRecord->type == PropType::Vector_real)
    {
        auto vecRealPropRecord = static_cast<PropRecord<std::vector<double>> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<std::vector<double>>>();
        retPropValue->type = PropType::Vector_real;
        retPropValue->value = vecRealPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    else if (propRecord->type == PropType::Vector_bool)
    {
        auto vecBoolPropRecord = static_cast<PropRecord<std::vector<bool>> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<std::vector<bool>>>();
        retPropValue->type = PropType::Vector_bool;
        retPropValue->value = vecBoolPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    else if (propRecord->type == PropType::Vector_Object)
    {
        auto vecObjPropRecord = static_cast<PropRecord<std::vector<std::shared_ptr<ClassInfo>>> *>(propRecord.get());
        auto retPropValue = std::make_shared<PropValue<std::vector<std::shared_ptr<ClassInfo>>>>();
        retPropValue->type = PropType::Vector_Object;
        retPropValue->value = vecObjPropRecord->get_func(pClass);
        return std::static_pointer_cast<PropValueBase>(retPropValue);
    }
    // invalid value
    else
    {
        return propValue;
    }
}


}


