//不能被继承的类

//常规解法：把构造函数设置为私有函数，缺点，不能在栈空间创建对象

class SealedClass1{
public:
	static SealedClass1* GetInstance(){
		return new SealedClass1();
	}
	static void DeleteInstance(SealedClass1* pInstance){
		delete pInstance;
	}
private:
	SealedClass1(){}
	~SealedClass1(){}
};

//利用虚拟继承的解法：友元关系不能被继承

template <typename T> class MakeSealed{
	friend T;
private:
	MakeSealed(){}
	~MakeSealed(){}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2>{
public:
	SealedClass2();
	~SealedClass2();
};