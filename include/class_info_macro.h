#ifndef _META_CORE_CLASS_INFO_MACRO_H_
#define _META_CORE_CLASS_INFO_MACRO_H_

#define TO_STR_(X) #X
#define TO_STR(X) TO_STR_(X)
#define class_info_namespace meta_core

#define CONTACT(a, b) a::b


#define META_CORE_CLASS_INFO_DECLARE_CLASS              \
    public:                                             \
        static const std::string g_class_name;          \
        const std::string &get_class_name() override    \
        {                                               \
            return  g_class_name;                       \
        }

// class register macro
#define META_CORE_CLASS_INFO_REGISTER_CLASS(class_name, space_class_name)           \
    const std::string class_name::g_class_name = #space_class_name;                 \
    class __ClassInfoHelper_##class_name                                            \
    {                                                                               \
        class RunOnce                                                               \
        {                                                                           \
        public:                                                                     \
            RunOnce()                                                               \
            {                                                                       \
                class_info_namespace::ClassInfo::register_class(#space_class_name,  \
                    [&]()->class_info_namespace::ClassInfo *{                       \
                        return new class_name();                                    \
                    });                                                             \
            }                                                                       \
        };                                                                          \
                                                                                    \
    public:                                                                         \
        __ClassInfoHelper_##class_name() {                                          \
            static RunOnce runOnce;                                                 \
        }                                                                           \
    };                                                                              \
    static __ClassInfoHelper_##class_name helper_##class_name ;




/*****************************************************************************/
/*                                                                           */
/*                          prop macro define                                */
/*                                                                           */
/*****************************************************************************/

#define META_CORE_CLASS_INFO_DECLARE_READ_FUNC(prop_name, T)    \
    const T &get_##prop_name() { return m_##prop_name; }

#define META_CORE_CLASS_INFO_DECLARE_WRITE_FUNC(prop_name, T)   \
    void set_##prop_name (const T &val) { m_##prop_name = val; }

// declare read write prop macro
#define META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, T)      \
    public:                                                     \
        META_CORE_CLASS_INFO_DECLARE_READ_FUNC(prop_name, T)    \
        META_CORE_CLASS_INFO_DECLARE_WRITE_FUNC(prop_name, T)   \
    protected:                                                  \
        T m_##prop_name;

// declare read only prop macro
#define META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, T)       \
    public:                                                     \
        META_CORE_CLASS_INFO_DECLARE_READ_FUNC(prop_name, T)    \
    protected:                                                  \
        META_CORE_CLASS_INFO_DECLARE_WRITE_FUNC(prop_name, T)   \
        T m_##prop_name;

// declare write only macro
#define META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, T)       \
    public:                                                     \
        META_CORE_CLASS_INFO_DECLARE_WRITE_FUNC(prop_name, T)   \
    protected:                                                  \
        META_CORE_CLASS_INFO_DECLARE_READ_FUNC(prop_name, T)    \
        T m_##prop_name;

// register read write prop macro
#define META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, T)                         \
    class __ClassInfoHelper_##class_name##_##prop_name                                          \
    {                                                                                           \
        class RunOnce                                                                           \
        {                                                                                       \
        public:                                                                                 \
            RunOnce()                                                                           \
            {                                                                                   \
                std::function<void(class_info_namespace::ClassInfo *, const T &)> set_func =    \
                        [](class_info_namespace::ClassInfo *pClass, const T &str) {             \
                            auto p##class_name = static_cast<class_name *>(pClass);             \
                            p##class_name->set_##prop_name(str);                                \
                        };                                                                      \
                                                                                                \
                std::function<const T&(class_info_namespace::ClassInfo *)> get_func =           \
                        [](class_info_namespace::ClassInfo *pClass)->const T& {                 \
                            auto p##class_name = static_cast<class_name *>(pClass);             \
                            return p##class_name->get_##prop_name();                            \
                        };                                                                      \
                                                                                                \
                class_info_namespace::ClassInfo::register_prop<T>                               \
                        (class_name::g_class_name,                                              \
                         #prop_name,                                                            \
                         class_info_namespace::PropAccessPermission::ReadWrite,                 \
                         set_func,                                                              \
                         get_func);                                                             \
            }                                                                                   \
        };                                                                                      \
    public:                                                                                     \
        __ClassInfoHelper_##class_name##_##prop_name()                                          \
        {                                                                                       \
            static RunOnce runOnce;                                                             \
        }                                                                                       \
    };                                                                                          \
    static __ClassInfoHelper_##class_name##_##prop_name helper_##class_name##_##prop_name ;

// register read only prop macro
#define META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, T)                          \
    class __ClassInfoHelper_##class_name##_##prop_name                                          \
    {                                                                                           \
        class RunOnce                                                                           \
        {                                                                                       \
        public:                                                                                 \
            RunOnce()                                                                           \
            {                                                                                   \
                std::function<void(class_info_namespace::ClassInfo *, const T &)> set_func;     \
                                                                                                \
                std::function<const T &(class_info_namespace::ClassInfo *)> get_func =          \
                        [](class_info_namespace::ClassInfo *pClass)->const T& {                 \
                            auto p##class_name = static_cast<class_name *>(pClass);             \
                            return p##class_name->get_##prop_name();                            \
                        };                                                                      \
                                                                                                \
                class_info_namespace::ClassInfo::register_prop<T>                               \
                        (class_name::g_class_name,                                              \
                         #prop_name,                                                            \
                         class_info_namespace::PropAccessPermission::ReadOnly,                  \
                         set_func,                                                              \
                         get_func);                                                             \
            }                                                                                   \
        };                                                                                      \
    public:                                                                                     \
        __ClassInfoHelper_##class_name##_##prop_name()                                          \
        {                                                                                       \
            static RunOnce runOnce;                                                             \
        }                                                                                       \
    };                                                                                          \
    static __ClassInfoHelper_##class_name##_##prop_name helper_##class_name##_##prop_name ;

// register write only prop macro
#define META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, T)                          \
    class __ClassInfoHelper_##class_name##_##prop_name                                          \
    {                                                                                           \
        class RunOnce                                                                           \
        {                                                                                       \
        public:                                                                                 \
            RunOnce()                                                                           \
            {                                                                                   \
                std::function<void(class_info_namespace::ClassInfo *, const T &)> set_func =    \
                        [](class_info_namespace::ClassInfo *pClass, const T &str) {             \
                            auto p##class_name = static_cast<class_name *>(pClass);             \
                            p##class_name->set_##prop_name(str);                                \
                        };                                                                      \
                                                                                                \
                std::function<const T&(class_info_namespace::ClassInfo *)> get_func;            \
                                                                                                \
                class_info_namespace::ClassInfo::register_prop<T>                               \
                        (class_name::g_class_name,                                              \
                         #prop_name,                                                            \
                         class_info_namespace::PropAccessPermission::WriteOnly,                 \
                         set_func,                                                              \
                         get_func);                                                             \
            }                                                                                   \
        };                                                                                      \
    public:                                                                                     \
        __ClassInfoHelper_##class_name##_##prop_name()                                          \
        {                                                                                       \
            static RunOnce runOnce;                                                             \
        }                                                                                       \
    };                                                                                          \
    static __ClassInfoHelper_##class_name##_##prop_name helper_##class_name##_##prop_name ;

/*-------------------------------------------------------*/
/*                  string prop macro                    */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_STR_PROP(prop_name)         \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, std::string)

#define META_CORE_CLASS_INFO_DECLARE_R_STR_PROP(prop_name)          \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, std::string)

#define META_CORE_CLASS_INFO_DECLARE_W_STR_PROP(prop_name)          \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, std::string)


// readwrite string prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_STR_PROP(class_name, prop_name)        \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, std::string)

// readonly string prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_STR_PROP(class_name, prop_name)         \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, std::string)

// writeonly string prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_STR_PROP(class_name, prop_name)         \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, std::string)

/*-------------------------------------------------------*/
/*                    real prop macro                    */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_REAL_PROP(prop_name)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, double)

#define META_CORE_CLASS_INFO_DECLARE_R_REAL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, double)

#define META_CORE_CLASS_INFO_DECLARE_W_REAL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, double)


// readwrite real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_REAL_PROP(class_name, prop_name)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, double)

// readonly real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_REAL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, double)

// writeonly real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_REAL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, double)

/*-------------------------------------------------------*/
/*                    bool prop macro                    */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_BOOL_PROP(prop_name)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, bool)

#define META_CORE_CLASS_INFO_DECLARE_R_BOOL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, bool)

#define META_CORE_CLASS_INFO_DECLARE_W_BOOL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, bool)


// readwrite bool prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_BOOL_PROP(class_name, prop_name)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, bool)

// readonly bool prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_BOOL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, bool)

// writeonly real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_BOOL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, bool)

/*-------------------------------------------------------*/
/*               obj(ClassInfo) prop macro               */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_OBJ_PROP(prop_name, T)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, std::shared_ptr<T>)

#define META_CORE_CLASS_INFO_DECLARE_R_OBJ_PROP(prop_name, T)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, std::shared_ptr<T>)

#define META_CORE_CLASS_INFO_DECLARE_W_OBJ_PROP(prop_name, T)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, std::shared_ptr<T>)


// readwrite obj prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_OBJ_PROP(class_name, prop_name, T)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, std::shared_ptr<T>)

// readonly obj prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_OBJ_PROP(class_name, prop_name, T)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, std::shared_ptr<T>)

// writeonly obj prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_OBJ_PROP(class_name, prop_name, T)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, std::shared_ptr<T>)

/*-------------------------------------------------------*/
/*               vector string prop macro                */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_VEC_STR_PROP(prop_name)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, std::vector<std::string>)

#define META_CORE_CLASS_INFO_DECLARE_R_VEC_STR_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, std::vector<std::string>)

#define META_CORE_CLASS_INFO_DECLARE_W_VEC_STR_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, std::vector<std::string>)


// readwrite vec str prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_VEC_STR_PROP(class_name, prop_name)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, std::vector<std::string>)

// readonly vec str prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_VEC_STR_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, std::vector<std::string>)

// writeonly vec str prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_VEC_STR_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, std::vector<std::string>)

/*-------------------------------------------------------*/
/*                 vector real prop macro                */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_VEC_REAL_PROP(prop_name)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, std::vector<double>)

#define META_CORE_CLASS_INFO_DECLARE_R_VEC_REAL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, std::vector<double>)

#define META_CORE_CLASS_INFO_DECLARE_W_VEC_REAL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, std::vector<double>)


// readwrite vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_VEC_REAL_PROP(class_name, prop_name)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, std::vector<double>)

// readonly vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_VEC_REAL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, std::vector<double>)

// writeonly vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_VEC_REAL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, std::vector<double>)

/*-------------------------------------------------------*/
/*                 vector bool prop macro                */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_VEC_BOOL_PROP(prop_name)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, std::vector<bool>)

#define META_CORE_CLASS_INFO_DECLARE_R_VEC_BOOL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, std::vector<bool>)

#define META_CORE_CLASS_INFO_DECLARE_W_VEC_BOOL_PROP(prop_name)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, std::vector<bool>)


// readwrite vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_VEC_BOOL_PROP(class_name, prop_name)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, std::vector<bool>)

// readonly vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_VEC_BOOL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, std::vector<bool>)

// writeonly vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_VEC_BOOL_PROP(class_name, prop_name)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, std::vector<bool>)

/*-------------------------------------------------------*/
/*                  vector obj prop macro                */
/*-------------------------------------------------------*/
#define META_CORE_CLASS_INFO_DECLARE_RW_VEC_OBJ_PROP(prop_name, T)     \
    META_CORE_CLASS_INFO_DECLARE_RW_PROP(prop_name, std::vector<std::shared_ptr<T>>)

#define META_CORE_CLASS_INFO_DECLARE_R_VEC_OBJ_PROP(prop_name, T)      \
    META_CORE_CLASS_INFO_DECLARE_R_PROP(prop_name, std::vector<std::shared_ptr<T>>)

#define META_CORE_CLASS_INFO_DECLARE_W_VEC_OBJ_PROP(prop_name, T)      \
    META_CORE_CLASS_INFO_DECLARE_W_PROP(prop_name, std::vector<std::shared_ptr<T>>)


// readwrite vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_RW_VEC_OBJ_PROP(class_name, prop_name, T)    \
    META_CORE_CLASS_INFO_REGISTER_RW_PROP(class_name, prop_name, std::vector<std::shared_ptr<T>>)

// readonly vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_R_VEC_OBJ_PROP(class_name, prop_name, T)     \
    META_CORE_CLASS_INFO_REGISTER_R_PROP(class_name, prop_name, std::vector<std::shared_ptr<T>>)

// writeonly vec real prop register macro
#define META_CORE_CLASS_INFO_REGISTER_W_VEC_OBJ_PROP(class_name, prop_name, T)     \
    META_CORE_CLASS_INFO_REGISTER_W_PROP(class_name, prop_name, std::vector<std::shared_ptr<T>>)




#endif
