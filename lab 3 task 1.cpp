#include <iostream>
using namespace std;

template <typename Type>
class List {
protected:
	Type* arr;
	int maxSize;
	int currentSize;

public:
	List(int size = 10) {
		maxSize = size;
		currentSize = 0;
		arr = new Type[maxSize];
	}

	List(const List<Type>& other) {
		maxSize = other.maxSize;
		currentSize = other.currentSize;
		arr = new Type[maxSize];
		for (int i = 0; i < currentSize; i++) {
			arr[i] = other.arr[i];
		}
	}

	virtual ~List() {
		delete[] arr;
	}

	virtual void addElementAtFirstIndex(Type element) = 0;
	virtual void addElementAtLastIndex(Type element) = 0;
	virtual void removeElementAtFirstIndex() = 0;
	virtual void removeElementAtLastIndex() = 0;
	virtual void display() const = 0;
};

template <typename Type>
class Temp : public List<Type> {
public:
	Temp(int a) : List<Type>(a) {}

	void addElementAtFirstIndex(Type element) {
		if (this->currentSize < this->maxSize) {
			for (int i = this->currentSize; i > 0; i--) {
				this->arr[i] = this->arr[i - 1];
			}
			this->arr[0] = element;
			this->currentSize++;
		}
		else {
			cout << "List is full!" << endl;
		}
	}

	void addElementAtLastIndex(Type element) {
		if (this->currentSize < this->maxSize) {
			this->arr[this->currentSize] = element;
			this->currentSize++;
		}
		else {
			cout << "List is full!" << endl;
		}
	}

	void removeElementAtFirstIndex() {
		if (this->currentSize > 0) {
			for (int i = 0; i < this->currentSize - 1; i++) {
				this->arr[i] = this->arr[i + 1];
			}
			this->currentSize--;
		}
		else {
			cout << "List is empty!" << endl;
		}
	}

	void removeElementAtLastIndex() {
		if (this->currentSize > 0) {
			this->currentSize--;
		}
		else {
			cout << "List is empty!" << endl;
		}
	}

	void display() const override {
		if (this->currentSize == 0) {
			cout << "List is empty!" << endl;
		}
		else {
			for (int i = 0; i < this->currentSize; i++) {
				cout << this->arr[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Temp<int> myList(5);

	myList.addElementAtFirstIndex(10);
	myList.addElementAtFirstIndex(20);
	myList.addElementAtLastIndex(30);
	myList.display();

	myList.removeElementAtFirstIndex();
	myList.display();

	myList.removeElementAtLastIndex();
	myList.display();

	cout << "Press Enter to continue...";
	cin.get();
	return 0;
}