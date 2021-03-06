//  File doc/quickbook/oglplus/quickref/enums/texture_swizzle_coord_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/texture_swizzle_coord.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_texture_swizzle_coord_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template <__TextureSwizzleCoord> class Transform>
class __EnumToClass<Base, __TextureSwizzleCoord, Transform> /*<
Specialization of __EnumToClass for the __TextureSwizzleCoord enumeration.
>*/
  : public Base {
public:
    EnumToClass();
    EnumToClass(Base&& base);

    Transform<TextureSwizzleCoord::R> R;
    Transform<TextureSwizzleCoord::G> G;
    Transform<TextureSwizzleCoord::B> B;
    Transform<TextureSwizzleCoord::A> A;
    Transform<TextureSwizzleCoord::RGBA> RGBA;
};

} // namespace enums
#endif
//]
