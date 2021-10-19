# Get Next Line
Reading a line on a fd is way too tedious

### What is the GNL project?
Get Next Line is the second individual project at [École 42](https://www.42sp.org.br/). It intends to devolop student skills in Rigor, Unix, and Algorithms & AI. Students are required to create a function similar to the getline from CPP and fgets from C.

### Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/victorfmartins/get_next_line.git && cd get_next_line/

# Create a main file
touch main.c
```

```c

/*
** Example of a main
*/

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("song.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		write(1, line, ft_strlen(line));
		free(line);
	}
}
```

```bash
# Compile the files, example:
clang get_next_line.c get_next_line.h get_next_line_utils.c main.c

# Execute your program
./a.out

# Well done!
```

### 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Made by Victor Martins [See my linkedin](https://www.linkedin.com/in/victor-franco-martins-1503a417b)