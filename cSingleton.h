#pragma once

// ���� ���� �߰� ��ũ��
#define COPYPREVENT(type)				\
	type(const type& rhw);				\
	type& operator=( const type& rhw );

// �̱��� ��ũ��
#define SINGLETON(type)					\
	COPYPREVENT(type)					\
	friend cSingleton<type>;
	
template < typename T >
class cSingleton
{
private:
	cSingleton( void ) {}
	virtual ~cSingleton( void ) {}
	
	// ���� ������ �� ���Կ��꿡 ���� ���� ��ũ�� 
	COPYPREVENT( cSingleton );
	
public:
	// �ν��Ͻ� ��������
	static T* GetInstance( void ); 
};

// �ν��Ͻ� ��������
template < typename T >
T* cSingleton<T>::GetInstance( void )
{
	static T instance;
	return& instance;
} 
