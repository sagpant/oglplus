//  File doc/quickbook/oglplus/quickref/enums/texture_compare_mode_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/texture_compare_mode.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_texture_compare_mode_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template <__TextureCompareMode> class Transform>
class __EnumToClass<Base, __TextureCompareMode, Transform> /*<
Specialization of __EnumToClass for the __TextureCompareMode enumeration.
>*/
  : public Base {
public:
    EnumToClass();
    EnumToClass(Base&& base);

    Transform<TextureCompareMode::None> None;
    Transform<TextureCompareMode::CompareRefToTexture> CompareRefToTexture;
};

} // namespace enums
#endif
//]
