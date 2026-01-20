# include "Serializer.hpp"

int main(void)
{
	Data *data = new Data();
	data->name = "Rui";
	std::cout << "data = " << data << "\n";
	std::cout << "data->name = " << data->name << "\n\n";

	uintptr_t ptr = Serializer::serialize(data);
	std::cout << "|| Data * serialized ||" << "\n";
	std::cout << "ptr = " << ptr << "\n\n";

	Data *new_data = Serializer::deserialize(ptr);
	std::cout << "|| uintptr_t deserialized ||" << "\n";
	std::cout << "new_data = " << new_data << std::endl;

	delete(data);
	return (0);
}