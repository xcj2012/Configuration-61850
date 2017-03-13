
/*
	Copyright 2006 - 2008, All Rights Reserved.
							
	这个类用来描述一个C++类成员函数地址

	作者	- 张鲁夺(zhangluduo)
	MSN		- zhangluduo@msn.com
	QQ群	- 34064264

	为所有爱我的人和我爱的人努力!
*/

#ifndef _MEMBERFXN_H
#define _MEMBERFXN_H

#ifndef _UNION_CAST
#define _UNION_CAST
	template <class ToType, class FromType>
	ToType union_cast (FromType f)
	{
		union 
		{
			FromType _f;
			ToType   _t;
		}	ut;
		ut._f = f;
		return ut._t;
	}
#endif

class MemberFxn 
{
private:

	void*			m_This;				// the this pointer of class
	unsigned long	m_MemberFxnAddr;	// member function address of class

public:
// construction

	MemberFxn( );
	MemberFxn( int n /* n must be zero */ );
	
	template<typename T> 
	MemberFxn( void* This, T MemberFxnName )
	{
		SetAddr( This, MemberFxnName );
	}

// destruction

	~MemberFxn( );

// over load operator

	MemberFxn&		operator =	( MemberFxn addr );
	bool			operator == ( MemberFxn addr ) ;

	bool			IsNull	( );
	void*			GetThis	( );
	unsigned long	GetAddr	( );

	/** set member function of a class, or a global function
		void* This		- a pointer of a object, if you will specify a global
						function, you must set this parameter zero
		T MemberFxnName	- member function name of a class, 
						for example
						&Class::MemberFunctionName or &GlobalFunctionName
	*/
	template<typename T> 
	void SetAddr( void* This, T MemberFxnName )
	{
		m_This			= This;
		m_MemberFxnAddr	= union_cast<unsigned long>( MemberFxnName );
	}
};

#endif