/// singleton.hpp

#pragma once

template< class T >
class singleton
{
public:

	singleton( ) = default;
	~singleton( ) = default;

	singleton( const singleton & ) = delete;
	singleton & operator=( const singleton & ) = delete;

	singleton( singleton && ) = delete;
	singleton & operator=( singleton && ) = delete;

	static T& get( )
	{
		static T p;

		return p;
	}
};
