// 为一个类型添加赋值运算符，注意几点：1.返回值类型为该类型引用，函数结束前返回自身引用
// 2.传入参数类型为常量引用，避免调用复制构造函数
// 3.释放自身空间防止内存泄露
// 4.判断是否是同一个实例，否则先释放了自己的内存会导致空指针异常
// 除此之外还要考虑内存不够分配时的异常，实现异常安全性

#include <cstring>
#include <cstdio>

class CMyString{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);

	void Print();
private:
	char* m_pData;
};

//不用再申明默认参数
CMyString::CMyString(char* pData){
	if(pData == NULL){
		m_pData = new char[1];
		m_pData = '\0';
	}else{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString &str){
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
	delete[] m_pData;
}

CMyString& CMyString::operator = (const CMyString& str){
	//这种实现不能保证异常安全性，如果内存不够，执行结束后m_pData = NULL
	// if(this == &str){
	// 	return *this;
	// }

	// delete[] m_pData;
	// m_pData = NULL;				//考虑这句的意义

	// m_pData = new char[strlen(str.m_pData) + 1];
	// strcpy(m_pData, str.m_pData);

	// return *this;

	if(this != &str){
		//利用临时变量在作用域后自动释放，同时利用拷贝构造函数创建空间

		CMyString strTemp(str);

		char* tmp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = tmp;
	}

	return *this;
}

// ================测试代码================
void CMyString::Print(){
	printf("%s", m_pData);
}

void Test1(){
	printf("Test1 begins:\n");

	char* text = "Hello world.";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

//赋值给自己
void Test2(){
	printf("Test2 begins:\n");

	char* text = "Hello world.";

	CMyString str1(text);

	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

//连续赋值
void Test3(){
	printf("Test3 begins:\n");

	char* text = "Hello world.";

	CMyString str1(text);
	CMyString str2, str3;

	str3 = str2 = str1;

	printf("The expected result is:%s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf("\n");

	str3.Print();
	printf("\n");
}

int main(){
	Test1();
	Test2();
	Test3();
	return 0;
}