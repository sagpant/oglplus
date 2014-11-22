/**
 *  .file oglplus/detail/prog_pl_stages.hpp
 *  .brief Helper class used by ProgramPipeline::UseStages
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_AUX_PROG_PL_STAGES_1107121519_HPP
#define OGLPLUS_AUX_PROG_PL_STAGES_1107121519_HPP

#include <oglplus/glfunc.hpp>
#include <oglplus/error/object.hpp>

namespace oglplus {

#if GL_VERSION_4_1 || GL_ARB_separate_shader_objects

class ProgPLUseStages
{
private:
	GLuint _pipeline, _program;
	GLbitfield _bits;

	GLbitfield _forward(void)
	noexcept
	{
		GLbitfield res = _bits;
		_bits = 0;
		return res;
	}

	inline
	ProgPLUseStages _make(GLbitfield bit)
	noexcept
	{
		return ProgPLUseStages(_pipeline, _program, _forward() | bit);
	}
public:
	ProgPLUseStages(const ProgPLUseStages&) = delete;

	ProgPLUseStages(GLuint pipeline, GLuint program, GLbitfield bits)
	noexcept
	 : _pipeline(pipeline)
	 , _program(program)
	 , _bits(bits)
	{ }

	ProgPLUseStages Vertex(void)
	noexcept
	{
		return _make(GL_VERTEX_SHADER_BIT);
	}

	ProgPLUseStages TessControl(void)
	noexcept
	{
		return _make(GL_TESS_CONTROL_SHADER_BIT);
	}

	ProgPLUseStages TessEvaluation(void)
	noexcept
	{
		return _make(GL_TESS_EVALUATION_SHADER_BIT);
	}

	ProgPLUseStages Geometry(void)
	noexcept
	{
		return _make(GL_GEOMETRY_SHADER_BIT);
	}

	ProgPLUseStages Fragment(void)
	noexcept
	{
		return _make(GL_FRAGMENT_SHADER_BIT);
	}

	ProgPLUseStages All(void)
	noexcept
	{
		return _make(GL_ALL_SHADER_BITS);
	}

	ProgPLUseStages(ProgPLUseStages&& temp)
	noexcept
	 : _pipeline(temp._pipeline)
	 , _program(temp._program)
	 , _bits(temp._forward())
	{ }

	void DoIt(void)
	{
		if(_bits)
		{
			assert(_pipeline);
			assert(_program);
			OGLPLUS_GLFUNC(UseProgramStages)(
				_pipeline,
				_bits,
				_program
			);
			OGLPLUS_VERIFY(
				UseProgramStages,
				ObjectError,
				Object(ProgramPipelineName(_pipeline))
			);
			_bits = 0;
		}
	}

	~ProgPLUseStages(void)
	noexcept
	{
		try{ DoIt(); }
		catch(...){ }
	}
};

#endif // program pipeline

} // namespace oglplus

#endif // include guard