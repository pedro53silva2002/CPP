#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] -= 32;
		}
	}
	i = 0;
	while (argv[++i])
		std::cout << argv[i];
	return (0);
}