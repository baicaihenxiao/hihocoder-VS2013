#include <IOSTREAM>

class CPPCollection {

public:

	class Iterator{

	public:

		int index;

		CPPCollection& outer;

		Iterator£¨CPPCollection &o, int i£© : outer£¨o£©£¬ index£¨i£©{}

		void operator++£¨£©{

			index++;

		}

		std::string operator*£¨£© const{

			return outer.str[index];

		}

		bool operator !=£¨Iterator i£©{

			return i.index != index - 1;

		}

	};

public:

	std::string str[10] {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

	Iterator begin£¨£©{

		return Iterator£¨*this, 0£©£»

	}

	Iterator end£¨£©{

		return Iterator£¨*this, 9£©£»

	}

};