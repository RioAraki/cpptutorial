# include <iostream>
# include <string>

//class Log {
//
//public:
//	enum Level {
//		LevelError = 0, LevelWarning = 1, LevelInfo = 2
//	};
//
//private:
//	Level m_LogLevel = LevelInfo; //class member variable which is private 
//
//public:
//	void SetLevel(Level level) { 
//		m_LogLevel = level;
//	}
//
//	void Warn(const char* message) {
//		if (m_LogLevel >= LevelWarning) {
//			std::cout << "[WARNING]: " << message << std::endl;
//		}
//	}
//
//	void Error(const char* message) {
//		if (m_LogLevel >= LevelError) {
//			std::cout << "[ERROR]: " << message << std::endl;
//		}
//	}
//
//	void Info(const char* message) {
//		if (m_LogLevel >= LevelInfo) {
//			std::cout << "[INFO]: " << message << std::endl;
//		}
//	}
//
//};
//
//int main() {
//
//	Log log; // instantiate the object
//	log.SetLevel(Log::LevelInfo);
//	log.Warn("Warning!");
//	log.Info("Warning!");
//	log.Error("Warning!");
//	std::cin.get();
//}


// Inheritance in C++

//class Entity {
//
//public:
//	float X, Y;
//
//	void Move(float xa, float ya) {
//		X += xa;
//		Y += ya;
//	}
//};
//
//
//class player : Entity {
//
//public:
//	const char* Name;
//
//	void PrintName(const char* Name) {
//		std::cout << Name << std::endl;
//	}
//
//};

// virtual and interface

//class Printable {
//public:
//	virtual std::string GetClassName() = 0;
//};
//
//class Entity : public Printable {
//public:
//	virtual std::string GetName() = 0;
//	std::string GetClassName() override { return "Entity"; }
//};
//
//class Player : public Entity {
//private:
//	std::string m_Name;
//public:
//	Player(const std::string& name)
//		: m_Name(name) {}
//
//	std::string GetName() override { return m_Name; }
//	std::string GetClassName() override { return "Player"; }
//};
//
//void PrintName(Entity* entity) {
//	std::cout << entity->GetName() << std::endl;
//}
//
//class A : public Printable {
//public:
//	std::string GetClassName() { return "A"; }
//};
//
//void Print(Printable* obj) {
//	std::cout << obj->GetClassName() << std::endl;
//}
//
//int main() {
//	Entity* e = new Player(""); //new returns a pointer to an object.
//	PrintName(e);
//	Player* p = new Player("cherno");
//	PrintName(p);
//
//	std::cin.get();
//}

// arrays

//int main() {
//
//	int example[5];
//	int* another = new int[5];
//
//	example[0] = 8;
//	std::cout << example[0] << std::endl;
//	std::cout << example << std::endl;
//
//
//	std::cin.get();
//}

//class Entity {
//private:
//	std::string m_Name;
//	int m_Score;
//
//public:
//	Entity() : m_Name("Unknown"), m_Score(0) {}
//
//	Entity(const std::string& name) {
//		m_Name = name;
//	}
//
//	const std::string& GetName() const {
//		return m_Name;
//	}
//};
//
//int main() {
//	Entity e0;
//	std::cout << e0.GetName() << std::endl;
//	Entity e1("Cherno");
//	std::cout << e1.GetName() << std::endl;
//
//	std::cin.get();
//}

class Entity {
public:
	Entity() {
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity() {
		std::cout << "Destroyed Entity!" << std::endl;
	}

};

class ScopedPtr {
private:
	Entity * m_Ptr;
public:
	ScopedPtr(Entity* ptr): m_Ptr(ptr){}
	~ScopedPtr(){
		delete m_Ptr;
	}
};


int* CreateArray() {

	//int array[50]  // wrong way, create on stack, and it would be cleared when function is terminated
	int* array = new int[50];
	return array;
}

int main() {
	{
		Entity e; // stack based
		Entity* e1 = new Entity(); // heap based
	}
}