#pragma once

// 복사 방지 추가 매크로
#define COPYPREVENT(type)					\
		type(const type& rhw);				\
		type& operator=( const type& rhw );

// 싱글톤 매크로
#define SINGLETON(type)					\
		COPYPREVENT(type)				\
		friend Singleton<type>;
	
template < typename T >
class Singleton
{
private:
	Singleton( void ) {}
	virtual ~Singleton( void ) {}
	
	// 복사 생성자 및 대입연산에 대한 방지 매크로 
	COPYPREVENT( Singleton );
	
public:
	// 인스턴스 가져오기
	static T* GetInstance( void ); 
};

// 인스턴스 가져오기
template < typename T >
T* Singleton<T>::GetInstance( void )
{
	static T instance;
	return& instance;
} 
