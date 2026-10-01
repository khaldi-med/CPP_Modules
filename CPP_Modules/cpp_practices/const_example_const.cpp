#include <iostream>

class Counter {
private:
	int count;

public:
  Counter() : count(0) {}
	// const at the end — only READS count, doesn't change it
	int get() const {
		return count;        // ✅ allowed
	}

	// const at the end — only READS count, doesn't change it
	void print() const {
		std::cout << count;  // ✅ allowed
	}

	// NO const — MODIFIES count, so it can't be const
	void increment() {
		count++;             // ✅ allowed
	}

	// This would cause a COMPILER ERROR:
	void broken() const {
		count++;             // ❌ error: you promised not to modify anything!
	}
};

int main(void) {
	Counter c;          // normal object — can call anything
	c.increment();      // ✅
	c.print();          // ✅

	const Counter c2;   // const object — can ONLY call const methods
	c2.print();         // ✅ print() is const
	c2.get();           // ✅ get() is const
	c2.increment();     // ❌ compiler error! increment() might modify the object
}
