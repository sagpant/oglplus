/**
 *  @file oglplus/shader.ipp
 *  @brief Implementation of Shader
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <oglplus/lib/incl_begin.ipp>
#include <oglplus/auxiliary/info_log.hpp>
#include <oglplus/lib/incl_end.ipp>

namespace oglplus {

OGLPLUS_LIB_FUNC
String ObjectOps<tag::DirectState, tag::Shader>::
GetInfoLog(void) const
{
	assert(_name != 0);
	return aux::GetInfoLog(
		_name, OGLPLUS_GLFUNC(GetShaderiv),
		OGLPLUS_GLFUNC(GetShaderInfoLog),
		"GetShaderiv",
		"GetShaderInfoLog"
	);
}

OGLPLUS_LIB_FUNC
void ObjectOps<tag::DirectState, tag::Shader>::
HandleCompileError(void) const
{
	HandleBuildError<CompileError>(
		GetInfoLog(),
		OGLPLUS_OBJECT_ERROR_INFO(
			CompileShader,
			Shader,
			EnumValueName(Type()),
			_name
		)
	);
}

} // namespace oglplus

