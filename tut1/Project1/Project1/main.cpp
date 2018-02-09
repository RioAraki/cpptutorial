# include <iostream>


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

class Entity {

public:
	float X, Y;

	void Move(float xa, float ya) {
		X += xa;
		Y += ya;
	}
};


class player : Entity {

public:
	const char* Name;

	void PrintName(const char* Name) {
		std::cout << Name << std::endl;
	}

};
