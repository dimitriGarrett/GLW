#pragma once

namespace GLW
{
	template <typename T, int components>
	struct vec { };

	template <typename T>
	struct vec<T, 1>
	{
		vec(T X)
			: x(X)
		{ }

		vec() = default;

		T x;
	};

	template <typename T>
	struct vec<T, 2>
	{
		vec(T X, T Y)
			: x(X), y(Y)
		{ }

		vec() = default;

		T x;
		T y;
	};

	template <typename T>
	struct vec<T, 3>
	{
		vec(T X, T Y, T Z)
			: x(X), y(Y), z(Z)
		{ }

		vec() = default;

		T x;
		T y;
		T z;
	};

	template <typename T>
	struct vec<T, 4>
	{
		vec(T X, T Y, T Z, T W)
			: x(X), y(Y), z(Z), w(W)
		{ }

		vec() = default;

		T x;
		T y;
		T z;
		T w;
	};

	using dvec2 = vec<double, 2>;
	using ivec4 = vec<int, 4>;
	using ivec2 = vec<int, 2>;
	using vec2 = vec<float, 2>;
}