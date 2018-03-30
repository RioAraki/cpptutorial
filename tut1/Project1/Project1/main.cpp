# include <iostream>
# include <string>
# include <memory>  // for smart pointer
# include <algorithm> // for lambda
# include <thread> // for thread
# include <chrono> // for time recording
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

//class Entity {
//public:
//	Entity() {
//		std::cout << "Created Entity!" << std::endl;
//	}
//
//	~Entity() {
//		std::cout << "Destroyed Entity!" << std::endl;
//	}
//
//	void Print() {}
//};
//
//int main() {
//	{
//		std::shared_ptr<Entity> e2;  // e2 is created
//		{
//			std::shared_ptr<Entity> entity = std::make_shared<Entity>(); // entity is created as a shared pointer
//			std::shared_ptr<Entity> e2 = entity; // assign e2 = entity
//		}  // entity dead because it is out of scope. but the shared ptr isnt dead because e2 still alive
//	} // the time when this shared pointer really dead
//}
////
#include <vector>

//struct Vertex {
//	float x, y, z;
//};
//
//std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
//	stream << vertex.x << "," << vertex.y << "," << vertex.z;
//	return stream;
//}
//
//int main() {
//	std::vector<Vertex> vertices; // in java you cant put primitive types inside, but you can do it in c++ since its just a template 
//	vertices.push_back({ 1,2,3 });
//	vertices.push_back({ 4,5,6 });
//
//	for (int i = 0; i < vertices.size(); i++)
//		std::cout << vertices[i] << std::endl;
//
//	for (const Vertex& v : vertices) // range based for loop
//		std::cout << v << std::endl;
//
//	vertices.erase(vertices.begin() + 1); // must erase an iterator
//	vertices.clear();
//	
//	std::cin.get();
//}

//template<typename T, int N>
//class Array {
//private:
//	T m_Array[N];
//public:
//	int GetSize() const { return N;  }
//};
//
//int main() {
//	Array<std::string, 10> array;
//	std::cout << array.GetSize() << std::endl;
//	std::cin.get();
//}


// lambda in c++
//void ForEach(const std::vector<int>& values, void(*func)(int)){
//	for (int value : values) {
//		func(value);
//	}
//}
//
//int main() {
//	std::vector<int> values = { 1,5,4,2,3 };
//	ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl; }); // [] -< usage of lambda
//	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; })
//	std::cin.get();
//}

// thread in c++

//static bool s_Finished = false; // use a static global variable as a flag
//
//void DoWork() {
//	while (!s_Finished) { // use the flag
//		std::cout << "working ..." << std::endl;
//		//std::cin.get(); // if we push it here, it would block the code from printing working
//	}
//
//}
//
//int main() {
//	std::thread worker(DoWork); // function pointer
//
//	std::cin.get();
//	s_Finished = true; // change the flag, so DoWork would finish the while loop and end
//
//	worker.join(); // let the current thread wait until worker thread finished
//	std::cin.get();
//
//}

// timing in c++

struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f; // must perform a type change or cannot print the result
		std::cout << "Timer took " << ms << "S" << std::endl;
	}
};

void Function() {
	Timer timer;

	for (int i = 0; i < 100; i++) {
		std::cout << "hello\n";
	}
}

int main() {
	Function();
	std::cin.get();
}