#pragma once

// ���� ���� �߰� ��ũ��
#define COPYPREVENT(type)					\
		type(const type& rhw);				\
		type& operator=( const type& rhw );

// �̱��� ��ũ��
#define SINGLETON(type)					\
		COPYPREVENT(type)				\
		friend Singleton<type>;
	
template < typename T >
class Singleton
{
private:
	Singleton( void ) {}
	virtual ~Singleton( void ) {}
	
	// ���� ������ �� ���Կ��꿡 ���� ���� ��ũ�� 
	COPYPREVENT( Singleton );
	
public:
	// �ν��Ͻ� ��������
	static T* GetInstance( void ); 
};

// �ν��Ͻ� ��������
template < typename T >
T* Singleton<T>::GetInstance( void )
{
	static T instance;
	return& instance;
} 
