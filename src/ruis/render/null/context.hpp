/*
ruis-render-null - null renderer

Copyright (C) 2024-2024  Ivan Gagis <igagis@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/* ================ LICENSE END ================ */

#pragma once

#include <ruis/render/context.hpp>

namespace ruis::render::null {

class context : public ruis::render::context
{
public:
	context() :
		ruis::render::context(parameters())
	{}

	// ===============================
	// ====== factory functions ======

	utki::shared_ref<ruis::render::context::shaders> make_shaders() override
	{
		return utki::make_shared<ruis::render::context::shaders>();
	}

	utki::shared_ref<ruis::render::frame_buffer> make_framebuffer(
		std::shared_ptr<ruis::render::texture_2d> color,
		std::shared_ptr<ruis::render::texture_depth> depth,
		std::shared_ptr<ruis::render::texture_stencil> stencil
	) override;

	utki::shared_ref<ruis::render::index_buffer> make_index_buffer(utki::span<const uint16_t> indices) override;
	utki::shared_ref<ruis::render::index_buffer> make_index_buffer(utki::span<const uint32_t> indices) override;

	utki::shared_ref<ruis::render::texture_2d> make_texture_2d(
		rasterimage::format format,
		rasterimage::dimensioned::dimensions_type dims,
		texture_2d_parameters params
	) override;

	utki::shared_ref<ruis::render::texture_2d> make_texture_2d(
		const rasterimage::image_variant& imvar,
		texture_2d_parameters params
	) override;

	utki::shared_ref<ruis::render::texture_2d> make_texture_2d(
		rasterimage::image_variant&& imvar,
		texture_2d_parameters params
	) override;

	utki::shared_ref<ruis::render::texture_depth> make_texture_depth(r4::vector2<uint32_t> dims) override;

	utki::shared_ref<ruis::render::texture_cube> make_texture_cube(
		rasterimage::image_variant&& positive_x,
		rasterimage::image_variant&& negative_x,
		rasterimage::image_variant&& positive_y,
		rasterimage::image_variant&& negative_y,
		rasterimage::image_variant&& positive_z,
		rasterimage::image_variant&& negative_z
	) override;

	utki::shared_ref<ruis::render::vertex_array> make_vertex_array(
		std::vector<utki::shared_ref<const ruis::render::vertex_buffer>> buffers,
		utki::shared_ref<const ruis::render::index_buffer> indices,
		ruis::render::vertex_array::mode rendering_mode
	) override;

	utki::shared_ref<ruis::render::vertex_buffer> make_vertex_buffer(utki::span<const float> vertices) override;

	utki::shared_ref<ruis::render::vertex_buffer> make_vertex_buffer(
		utki::span<const r4::vector2<float>> vertices
	) override;

	utki::shared_ref<ruis::render::vertex_buffer> make_vertex_buffer(
		utki::span<const r4::vector3<float>> vertices
	) override;

	utki::shared_ref<ruis::render::vertex_buffer> make_vertex_buffer(
		utki::span<const r4::vector4<float>> vertices
	) override;

	// =====================================
	// ====== state control functions ======

	void clear_framebuffer_color() override {}

	void clear_framebuffer_depth() override {}

	void clear_framebuffer_stencil() override {}

	r4::vector2<uint32_t> to_window_coords(ruis::vec2 point) const override
	{
		return {0, 0};
	}

	r4::rectangle<uint32_t> get_scissor() const override
	{
		return {0, 0};
	}

	r4::rectangle<uint32_t> get_viewport() const override
	{
		return {0, 0};
	}

	bool is_scissor_enabled() const noexcept override
	{
		return false;
	}

	void enable_blend(bool enable) override {}

	void set_blend_func(
		blend_factor src_color,
		blend_factor dst_color,
		blend_factor src_alpha,
		blend_factor dst_alpha
	) override
	{}

	void set_framebuffer_internal(ruis::render::frame_buffer* fb) override {}

	void enable_scissor(bool enable) override {}

	void set_scissor(r4::rectangle<uint32_t> r) override {}

	void set_viewport(r4::rectangle<uint32_t> r) override {}

	bool is_depth_enabled() const noexcept override
	{
		return false;
	}

	void enable_depth(bool enable) override {}
};

} // namespace ruis::render::null