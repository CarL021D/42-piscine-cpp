#include <stdint.h>

typedef struct Data {
	int		nbr;
} 	Data;

class Serializer {
	public:
			Serializer();
			~Serializer();
			Serializer(const Serializer& src);
			Serializer& operator=(const Serializer& rhs);
			
			static uintptr_t	serialize(Data* ptr);
			static Data*		deserialize(uintptr_t raw);
};