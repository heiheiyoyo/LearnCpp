
auto func(int value) -> int(*)[10]
{
	int array[10]{0};
	return &array;
}

int main()
{
	auto a=func(5);
	return (*a)[3];
}
