/// vector.hpp

#pragma once

#include "../cui.hpp"

namespace cui
{
	template < int N = 2,
			   typename T = double >
	struct vector
	{
		std::array< T, N > s;

		__declspec( property( get = get_x, put = put_x ) ) T x;
		__declspec( property( get = get_y, put = put_y ) ) T y;
		__declspec( property( get = get_z, put = put_z ) ) T z;

		template< typename ... I >
		vector( I ... args )
		{
			static_assert( sizeof ... ( args ) == N );
			s = { args ... };
		}

		T & get( int index );
		void put( int index,
				  T const val );

		T & get_x( );
		void put_x( T const val );
		T & get_y( );
		void put_y( T const val );
		T & get_z( );
		void put_z( T const val );
	};

	using vec2d = vector< 2, int >;
	using vec3d = vector< 3, int >;

	template < int N, typename T >
	T & vector< N, T >::get( int index )
	{
		return s[ index ];
	}

	template < int N, typename T >
	void vector< N, T >::put( int index,
							  T const val )
	{
		s[ index ] = val;
	}

	template < int N, typename T >
	T & vector< N, T >::get_x( )
	{
		return get( 0 );
	}

	template < int N, typename T >
	void vector< N, T >::put_x( T const val )
	{
		return put( 0,
					val );
	}

	template < int N, typename T >
	T & vector< N, T >::get_y( )
	{
		return get( 1 );
	}

	template < int N, typename T >
	void vector< N, T >::put_y( T const val )
	{
		return put( 1,
					val );
	}

	template < int N, typename T >
	T & vector< N, T >::get_z( )
	{
		return get( 2 );
	}

	template < int N, typename T >
	void vector< N, T >::put_z( T const val )
	{
		return put( 2,
					val );
	}
}
