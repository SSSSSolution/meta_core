#ifndef _META_CORE_TEMPLATE_TOOL_H_
#define _META_CORE_TEMPLATE_TOOL_H_

#include <memory>
#include <vector>

namespace meta_core
{

template<typename T1, typename T2>
struct is_base_of_smart_ptr_inside_type
{
    static constexpr bool value = false;
};

template<typename T, typename InsideT>
struct is_base_of_smart_ptr_inside_type< T, std::shared_ptr<InsideT> >
{
    static constexpr bool value = std::is_base_of<T, InsideT>::value;
};



template<typename T1, typename T2>
struct is_base_of_smart_ptr_vec_inside_type
{
    static constexpr bool value = false;
};

template<typename T, typename InsideT>
struct is_base_of_smart_ptr_vec_inside_type< T, std::vector<std::shared_ptr<InsideT>> >
{
    static constexpr bool value = std::is_base_of<T, InsideT>::value;
};


}


#endif
