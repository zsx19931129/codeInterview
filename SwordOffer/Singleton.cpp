// c++ 实现单例模式

class Singleton{
private:
	static Singleton* m_instance;
	Singleton(){}
public:
	static Singleton* getInstance();
};

Singleton* Singleton::getInstance(){
	if(m_instance == NULL){
		Lock();			//创建实例前加锁，使用其他类实现，如boost
		if(m_instance == NULL){
			m_instance = new Singleton();
		}
		UnLock();
	}
	return m_instance;
}
