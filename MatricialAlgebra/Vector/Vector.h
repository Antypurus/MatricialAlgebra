#include<vector>


namespace MatricialAlgebra {
	template<typename T>
	class Vector {
	private:
		size_t m_Size=0;
		std::vector<T>m_Vector;
		bool m_isNULL = false;
	public:
		/*
		Standard Constructor For the Vector , all values will be instanced as 0
		and the number of values to the vector is passed as an argument
		@param size - size of the mathematical vector
		*/
		Vector(size_t size);

		/*
		Returns the size of the vector object
		@return - the number of values in the vector
		*/
		size_t getSize()const;
	};
}