#pragma once

namespace only2d
{
	class Vector
	{
	public:
		Vector();

		Vector(float x, float y);

		void set(float x, float y);

		float getLength() const;

		float normalize(float length = 1.0);

		Vector getNormal() const;

		Vector getNormal(float scale) const;

		Vector operator+(const Vector &vector) const;

		Vector operator-(const Vector &vector) const;

		Vector operator*(float scale) const;

		Vector operator/(float scale) const;

		Vector operator-() const;

		void operator+=(const Vector &vector);

		void operator-=(const Vector &vector);

		void operator*=(float scale);

		void operator/=(float scale);

		float operator*(const Vector &vector) const;

		float operator^(const Vector &vector) const;

		bool operator==(const Vector &vector) const;

		bool operator<(const Vector &vector) const;

		float x;
		float y;
	};
}